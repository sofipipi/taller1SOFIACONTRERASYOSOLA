#include "Revista.h"
using namespace std;
#include <iostream>

Revista::Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

void Revista::mostrarInformacion() const {
    cout << "Revista: " << nombre << ", ISBN: " << isbn << ", Autor: " << autor
              << ", Edición: " << numeroEdicion << ", Mes: " << mesPublicacion << std::endl;
}

