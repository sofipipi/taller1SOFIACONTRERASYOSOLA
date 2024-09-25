#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "MaterialBibliografico.h"

class Usuario {
private:
    std::string nombre;
    int id;
    int numPrestados;
    std::vector<MaterialBibliografico*> materialesPrestados;

public:
    Usuario(std::string nombre, int id);

    std::string getNombre() const;
    int cantidadPrestados() const;

    bool prestarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(MaterialBibliografico* material);
};

#endif // USUARIO_H


