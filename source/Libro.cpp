#include "Libro.h"
#include <iostream>

// Constructor
Libro::Libro(const std::string& nombre, const std::string& isbn, const std::string& autor,
             const std::string& fechaPublicacion, const std::string& resumen)
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

// Sobreescritura de mostrarInformacion
void Libro::mostrarInformacion() const {
    std::cout << "Libro: " << nombre << "\n"
              << "Autor: " << autor << "\n"
              << "ISBN: " << isbn << "\n"
              << "Fecha de Publicación: " << fechaPublicacion << "\n"
              << "Resumen: " << resumen << "\n"
              << (estaPrestado() ? "Prestado\n" : "Disponible\n");
}



