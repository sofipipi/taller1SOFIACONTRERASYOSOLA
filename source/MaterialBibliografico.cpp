#include "MaterialBibliografico.h"
using namespace std;

// Constructor de MaterialBibliografico
MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor)
    : nombre(nombre), isbn(isbn), autor(autor), estaPrestado(false) {}


// Implementación de la función para obtener el nombre
std::string MaterialBibliografico::getNombre() const {
    return nombre;
}

// Implementación de la función para prestar el material
void MaterialBibliografico::prestar() {
    prestado = true;
}

// Implementación de la función para devolver el material
void MaterialBibliografico::devolver() {
    prestado = false;
}


