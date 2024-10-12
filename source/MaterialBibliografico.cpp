#include "MaterialBibliografico.h"

// Definición del constructor
MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(false) {}

// Método que indica si el material está prestado
bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

// Método para prestar el material
void MaterialBibliografico::prestar() {
    prestado = true;
}

// Método para devolver el material
void MaterialBibliografico::devolver() {
    prestado = false;
}

// Getter para el nombre del material
std::string MaterialBibliografico::getNombre() const {
    return nombre;
}

// Implementación del método estático buscarMaterial
MaterialBibliografico* MaterialBibliografico::buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const std::string& titulo) {
    for (int i = 0; i < numMateriales; ++i) {
        if (biblioteca[i]->getNombre() == titulo) {
            return biblioteca[i];  // Retorna el material si se encuentra
        }
    }
    return nullptr;  // Retorna nullptr si no se encuentra el material
}







