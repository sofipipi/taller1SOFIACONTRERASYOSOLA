#pragma once
#include "MaterialBibliografico.h"
#include <string>

class Libro : public MaterialBibliografico {
private:
    std::string fechaPublicacion;
    std::string resumen;
public:
    Libro(const std::string& nombre, const std::string& isbn, const std::string& autor,
          const std::string& fechaPublicacion, const std::string& resumen);

    // Sobreescribir la función mostrarInformacion
    void mostrarInformacion() const override;
};



