#pragma once
#include "MaterialBibliografico.h"
#include <string>

class Revista : public MaterialBibliografico {
private:
    int numeroEdicion;
    std::string mesPublicacion;
public:
    Revista(const std::string& nombre, const std::string& isbn, const std::string& autor, 
            int numeroEdicion, const std::string& mesPublicacion);

    // Sobreescribir la función mostrarInformacion
    void mostrarInformacion() const override;
};



