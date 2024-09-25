#pragma once
#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool prestado; // Indica si el material está prestado o no

public:
    // Constructor que recibe nombre, ISBN y autor
    MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor);

    // Método para verificar si el material está prestado
    bool estaPrestado() const;

    // Métodos para prestar y devolver el material
    void prestar();
    void devolver();

    // Método virtual para mostrar la información del material
    virtual void mostrarInformacion() const = 0;

    // Getter para el nombre del material
    std::string getNombre() const;
};

