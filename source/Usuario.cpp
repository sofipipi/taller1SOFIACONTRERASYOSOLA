#include "Usuario.h"
#include <iostream>
#include <algorithm>  // Para std::find

bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    // Busca el material en el vector de materiales prestados
    auto it = std::find(materialesPrestados.begin(), materialesPrestados.end(), material);

    // Si se encuentra, lo devuelve
    if (it != materialesPrestados.end()) {
        material->setPrestado(false);
        materialesPrestados.erase(it);  // Elimina el material del vector
        numPrestados--;
        return true;
    } else {
        std::cerr << "Error: el usuario no ha prestado este material.\n";
        return false;
    }
}



