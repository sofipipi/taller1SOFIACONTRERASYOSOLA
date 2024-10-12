#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

using namespace std;

const int MAX_MATERIALES = 100;
const int MAX_USUARIOS = 50;

// Funciones para cargar datos desde archivos
void cargarBiblioteca(MaterialBibliografico* biblioteca[], int& numMateriales);
void cargarUsuarios(vector<Usuario>& usuarios);
void cargarPrestamos(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales);

// Funciones del menú
void mostrarMateriales(MaterialBibliografico* biblioteca[], int numMateriales);
MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const string& titulo);
Usuario* buscarUsuario(vector<Usuario>& usuarios, const string& nombre);
// Función para prestar material
void prestarMaterial(std::vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales);
void devolverMaterial(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales);

// Manejo de errores
void actualizarPrestamos(const Usuario& usuario, const MaterialBibliografico* material);
bool verificarCapacidad(int numMateriales, int maxMateriales);
bool verificarPrestamo(Usuario* usuario, MaterialBibliografico* material);

int main(){
    MaterialBibliografico* biblioteca[MAX_MATERIALES];
    
    int numMateriales = 0;
    vector<Usuario> usuarios;

    cargarBiblioteca(biblioteca, numMateriales);
    cargarUsuarios(usuarios);
    cargarPrestamos(usuarios, biblioteca, numMateriales);

    int opcion;
    do {
        cout << "Simulador de Biblioteca Digital\n";
        cout << "1. Mostrar Materiales\n";
        cout << "2. Prestar Material\n";
        cout << "3. Devolver Material\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarMateriales(biblioteca, numMateriales);
                break;
            case 2:
                prestarMaterial(usuarios, biblioteca, numMateriales);
                break;
            case 3:
                devolverMaterial(usuarios, biblioteca, numMateriales);
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 4);

    // Liberar memoria
    for (int i = 0; i < numMateriales; ++i) {
        delete biblioteca[i];
    }

    return 0;
}

void cargarBiblioteca(MaterialBibliografico* biblioteca[], int& numMateriales) {
    ifstream archivo("Biblioteca.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo Biblioteca.txt\n";
        return;
    }

    string tipo, nombre, isbn, autor, extra1, extra2;

    while (true) {
        // Leer tipo
        if (!getline(archivo, tipo, ',')) {
            if (archivo.eof()) break; // Si es el final del archivo, salir del bucle
            cerr << "Error al leer el tipo de material.\n";
            break;
        }

        // Leer nombre
        if (!getline(archivo, nombre, ',')) {
            cerr << "Error al leer el nombre del material.\n";
            break;
        }

        // Leer ISBN
        if (!getline(archivo, isbn, ',')) {
            cerr << "Error al leer el ISBN.\n";
            break;
        }

        // Leer autor
        if (!getline(archivo, autor, ',')) {
            cerr << "Error al leer el autor.\n";
            break;
        }

        if (tipo == "Libro") {
            // Leer fecha de publicación
            if (!getline(archivo, extra1, ',')) {
                cerr << "Error al leer la fecha de publicación del libro.\n";
                break;
            }

            // Leer resumen
            if (!getline(archivo, extra2)) {
                cerr << "Error al leer el resumen del libro.\n";
                break;
            }

            // Agregar el libro a la biblioteca
            biblioteca[numMateriales++] = new Libro(nombre, isbn, autor, extra1, extra2);

        } else if (tipo == "Revista") {
            int numeroEdicion;

            // Leer número de edición
            if (!(archivo >> numeroEdicion)) {
                cerr << "Error al leer el número de edición de la revista.\n";
                break;
            }

            archivo.ignore(); // Ignorar la coma después del número de edición

            // Leer mes de publicación
            if (!getline(archivo, extra1)) {
                cerr << "Error al leer el mes de publicación de la revista.\n";
                break;
            }

            // Agregar la revista a la biblioteca
            biblioteca[numMateriales++] = new Revista(nombre, isbn, autor, numeroEdicion, extra1);
        } else {
            cerr << "Tipo de material no reconocido: " << tipo << "\n";
            break;
        }

        // Verificar capacidad máxima
        if (!verificarCapacidad(numMateriales, MAX_MATERIALES)) {
            cerr << "Capacidad máxima de la biblioteca alcanzada.\n";
            break;
        }
    }

    archivo.close();
}

void cargarUsuarios(vector<Usuario>& usuarios) {
    ifstream archivo("Usuarios.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo Usuarios.txt\n";
        return;
    }

    string nombre, material;
    while (getline(archivo, nombre, ',')) {
        getline(archivo, material); // Ignorar el material por ahora
        usuarios.push_back(Usuario(nombre, usuarios.size() + 1));
    }
    archivo.close();
}

void cargarPrestamos(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales) {
    ifstream archivo("Prestamos.txt");
    if (!archivo) {
        cerr << "Error al abrir el archivo Prestamos.txt\n";
        return;
    }

    string nombreUsuario, tituloMaterial;
    while (getline(archivo, nombreUsuario, ',')) {
        getline(archivo, tituloMaterial);
        Usuario* usuario = buscarUsuario(usuarios, nombreUsuario);
        MaterialBibliografico* material = buscarMaterial(biblioteca, numMateriales, tituloMaterial);
        if (usuario && material && !material->estaPrestado()) {
            usuario->prestarMaterial(material);
        }
    }
    archivo.close();
}

void mostrarMateriales(MaterialBibliografico* biblioteca[], int numMateriales) {
    for (int i = 0; i < numMateriales; ++i) {
        if (biblioteca[i] != nullptr) {  // Verifica que el puntero no sea nulo
            string nom = biblioteca[i]->getNombre();
            cout << "Material " << i + 1 << ": " << nom << endl;
        } else {
            cout << "Error: Material " << i + 1 << " es nulo." << endl;
        }
    }
}

MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const string& titulo) {
    for (int i = 0; i < numMateriales; ++i) {
        if (biblioteca[i]->getNombre() == titulo) {
            return biblioteca[i];
        }
    }
    return nullptr; // Devuelve nullptr si no se encuentra el material
}


Usuario* buscarUsuario(vector<Usuario>& usuarios, const string& nombre) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            return &usuario; // Devuelve el puntero al usuario si se encuentra
        }
    }
    return nullptr; // Devuelve nullptr si no se encuentra el usuario
}


// Ejemplo de definición de devolverMaterial
void devolverMaterial(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales) {
    string nombreUsuario, tituloMaterial;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese el título del material: ";
    cin.ignore();
    getline(cin, tituloMaterial);

    Usuario* usuario = buscarUsuario(usuarios, nombreUsuario);
    MaterialBibliografico* material = buscarMaterial(biblioteca, numMateriales, tituloMaterial);

    if (usuario && material) {
        if (usuario->devolverMaterial(material)) {
            cout << "Material devuelto con éxito.\n";
        } else {
            cerr << "Error: No se puede devolver el material.\n";
        }
    } else {
        cerr << "Error: Usuario o material no encontrado.\n";
    }
}

// Ejemplo de definición de verificarCapacidad
bool verificarCapacidad(int numMateriales, int maxMateriales) {
    return numMateriales < maxMateriales;
}

// Ejemplo de definición de verificarPrestamo
bool verificarPrestamo(Usuario* usuario, MaterialBibliografico* material) {
    if (usuario->cantidadPrestados() >= 5) {
        cerr << "Error: El usuario ya tiene 5 materiales prestados.\n";
        return false;
    }
    if (material->estaPrestado()) {
        cerr << "Error: El material ya está prestado.\n";
        return false;
    }
    return true;
}

void prestarMaterial(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales) {
    string nombreUsuario, tituloMaterial;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese el título del material: ";
    cin.ignore();
    getline(cin, tituloMaterial);

    Usuario* usuario = buscarUsuario(usuarios, nombreUsuario);
    MaterialBibliografico* material = buscarMaterial(biblioteca, numMateriales, tituloMaterial);

    // Depuración
    if (!usuario) {
        cout << "Usuario no encontrado: " << nombreUsuario << endl;
    }
    if (!material) {
        cout << "Material no encontrado: " << tituloMaterial << endl;
    }

    if (usuario && material) {
        if (!material->estaPrestado()) {
            // No está prestado, verificar capacidad
            if (verificarPrestamo(usuario, material)) {
                material->prestar(); // Cambiar el estado del material a prestado
                usuario->prestarMaterial(material);
                cout << "Material prestado con éxito.\n";
                actualizarPrestamos(*usuario, material);
            } else {
                cout << "Error: El usuario no puede prestar más materiales.\n";
            }
        } else {
            cerr << "Error: El material ya está prestado.\n";
        }
    } else {
        cerr << "Error: Usuario o material no encontrado.\n";
    }
}

void actualizarPrestamos(const Usuario& usuario, const MaterialBibliografico* material) {
    ofstream archivo("Prestamos.txt", ios::app); // Abre en modo agregar
    if (!archivo) {
        cerr << "Error al abrir el archivo de préstamos.\n";
        return;
    }
    archivo << usuario.getNombre() << "," << material->getNombre() << endl;
    archivo.close();
}





