#pragma once
#include <string>
#include "MaterialBibliografico.h"
using namespace std;
#include <iostream>


class Usuario {
private:
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
    int numPrestados;

public:
    Usuario(string nombre, int id) : nombre(nombre), id(id), numPrestados(0) {}

    string getNombre() const { return nombre; }

    int cantidadPrestados() const { return numPrestados; }

    bool prestarMaterial(MaterialBibliografico* material) {
        if (numPrestados < 5) {
            materialesPrestados[numPrestados++] = material;
            material->setPrestado(true);
            return true;
        }
        return false;
    }

    bool devolverMaterial(MaterialBibliografico* material) {
        for (int i = 0; i < numPrestados; ++i) {
            if (materialesPrestados[i] == material) {
                for (int j = i; j < numPrestados - 1; ++j) {
                    materialesPrestados[j] = materialesPrestados[j + 1];
                }
                numPrestados--;
                material->setPrestado(false);
                return true;
            }
        }
        return false;
    }
};

