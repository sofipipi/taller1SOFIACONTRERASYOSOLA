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




