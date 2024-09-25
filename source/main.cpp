#pragma once
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
void prestarMaterial(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales);
void devolverMaterial(vector<Usuario>& usuarios, MaterialBibliografico* biblioteca[], int numMateriales);

// Manejo de errores
bool verificarCapacidad(int numMateriales, int maxMateriales);
bool verificarPrestamo(Usuario* usuario, MaterialBibliografico* material);

int main() {
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
    while (archivo >> tipo) {
        archivo.ignore(); // Ignorar la coma
        getline(archivo, nombre, ',');
        getline(archivo, isbn, ',');
        getline(archivo, autor, ',');

        if (tipo == "Libro") {
            getline(archivo, extra1, ',');  // Fecha de Publicación
            getline(archivo, extra2);       // Resumen
            biblioteca[numMateriales++] = new Libro(nombre, isbn, autor, extra1, extra2);
        } else if (tipo == "Revista") {
            int numeroEdicion;
            archivo >> numeroEdicion;
            archivo.ignore(); // Ignorar la coma
            getline(archivo, extra1);  // Mes de Publicación
            biblioteca[numMateriales++] = new Revista(nombre, isbn, autor, numeroEdicion, extra1);
        }

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
        biblioteca[i]->mostrarInformacion();
        cout << endl;
    }
}

MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const string& titulo) {
    for (int i = 0; i < numMateriales; ++i) {
        if (biblioteca[i]->getNombre() == titulo) {
            return biblioteca[i];
        }
    }
    return nullptr;
}

Usuario* buscarUsuario(vector<Usuario>& usuarios, const string& nombre) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            return &usuario;
        }
    }
    return nullptr;
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

    if (usuario && material && verificarPrestamo(usuario, material)) {
        material->prestar(); // Usar el método prestar() del material
        usuario->prestarMaterial(material);
        cout << "Material prestado con éxito.\n";
    } else {
        cerr << "Error: No se puede prestar el material.\n";
    }
}

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
        material->devolver(); // Usar el método devolver() del material
        usuario->devolverMaterial(material);
        cout << "Material devuelto con éxito.\n";
    } else {
        cerr << "Error: No se puede devolver el material.\n";
    }
}

// Manejo de errores y validaciones
bool verificarCapacidad(int numMateriales, int maxMateriales) {
    return numMateriales < maxMateriales;
}

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

