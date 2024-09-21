#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"
#include <iostream>
#include <string>

using namespace std;

class Libro : public MaterialBibliografico {
private:
    string fechaPublicacion;
    string resumen;

public:
    Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen);
    void mostrarInformacion() const override;
};

#endif // LIBRO_H


