#include "Libro.h"

Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen)
    : MaterialBibliografico(nombre, isbn, autor), fechaPublicacion(fechaPublicacion), resumen(resumen) {}

void Libro::mostrarInformacion() const {
    cout << "Libro: " << nombre << ", ISBN: " << isbn << ", Autor: " << autor
         << ", Publicado en: " << fechaPublicacion << ", Resumen: " << resumen << endl;
}


