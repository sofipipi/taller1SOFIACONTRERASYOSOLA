#include "MaterialBibliografico.h"

// constructor
MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(false) {}


bool MaterialBibliografico::estaPrestado() const {
    return prestado;
}

//  prestar el material
void MaterialBibliografico::prestar() {
    prestado = true;
}

// devolver el material
void MaterialBibliografico::devolver() {
    prestado = false;
}

// Getter 
std::string MaterialBibliografico::getNombre() const {
    return nombre;
}


MaterialBibliografico* MaterialBibliografico::buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const std::string& titulo) {
    for (int i = 0; i < numMateriales; ++i) {
        if (biblioteca[i]->getNombre() == titulo) {
            return biblioteca[i];  // Retorna el material si se encuentra
        }
    }
    return nullptr;  // Retorna nullptr si no se encuentra el material
}







