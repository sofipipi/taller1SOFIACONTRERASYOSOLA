#include "Revista.h"
#include <iostream>

// Constructor
Revista::Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, 
                 int numeroEdicion, const std::string& mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}


void Revista::mostrarInformacion() const {
    std::cout << "Revista: " << nombre << "\n"
              << "Autor: " << autor << "\n"
              << "ISBN: " << isbn << "\n"
              << "Número de Edición: " << numeroEdicion << "\n"
              << "Mes de Publicación: " << mesPublicacion << "\n"
              << (estaPrestado() ? "Prestado\n" : "Disponible\n");
}



