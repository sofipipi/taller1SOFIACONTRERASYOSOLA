#include "Usuario.h"
#include <iostream>
#include <algorithm>  // Para std::find

// Constructor
Usuario::Usuario(const std::string& nombre, int id) : nombre(nombre), id(id) {}

// Obtener el nombre del usuario
std::string Usuario::getNombre() const {
    return nombre;
}

// Contar materiales prestados
int Usuario::cantidadPrestados() const {
    return materialesPrestados.size();
}

// Prestar material
bool Usuario::prestarMaterial(MaterialBibliografico* material) {
    if (!material->estaPrestado()) {
        materialesPrestados.push_back(material);
        material->prestar();  // Cambia el estado del material a prestado
        return true;
    } else {
        std::cerr << "Error: el material ya está prestado.\n";
        return false;
    }
}

// Devolver material
bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    // Busca el material en el vector de materiales prestados
    auto it = std::find(materialesPrestados.begin(), materialesPrestados.end(), material);
    
    // Si se encuentra, lo devuelve
    if (it != materialesPrestados.end()) {
        material->devolver();  // Cambia el estado del material a disponible
        materialesPrestados.erase(it);  // Elimina el material del vector
        return true;
    } else {
        std::cerr << "Error: el usuario no ha prestado este material.\n";
        return false;
    }
}






