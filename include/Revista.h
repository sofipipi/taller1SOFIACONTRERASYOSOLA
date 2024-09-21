#pragma once
#include "MaterialBibliografico.h"
#include <iostream>

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    string mesPublicacion;

public:
    Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion)
        : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {}

    void mostrarInformacion() const override {
        cout << "Revista: " << nombre << ", ISBN: " << isbn << ", Autor: " << autor
             << ", Edición: " << numeroEdicion << ", Mes: " << mesPublicacion << endl;
    }
};

