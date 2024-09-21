#include "Usuario.h"
using namespace std;
#include <iostream>

Usuario::Usuario(string nombre, int id) : nombre(nombre), id(id), numPrestados(0) {}

string Usuario::getNombre() const {
    return nombre;
}

int Usuario::cantidadPrestados() const {
    return numPrestados;
}

bool Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (numPrestados < 5) {
        materialesPrestados[numPrestados++] = material;
        material->setPrestado(true);
        return true;
    } else {
        std::cerr << "Error: No puedes prestar más de 5 materiales.\n";
        return false;
    }
}

bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < numPrestados; ++i) {
        if (materialesPrestados[i] == material) {
            // Desplazar elementos en el array
            for (int j = i; j < numPrestados - 1; ++j) {
                materialesPrestados[j] = materialesPrestados[j + 1];
            }
            numPrestados--;
            material->setPrestado(false);
            return true;
        }
    }
    std::cerr << "Error: Material no encontrado en los préstamos del usuario.\n";
    return false;
}

