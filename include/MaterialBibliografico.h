#pragma once
#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;  // Nombre del material
    std::string isbn;    // ISBN del material
    std::string autor;   // Autor del material
    bool prestado=false;       // Indica si el material está prestado o no

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

    // Método estático para buscar un material en la biblioteca
    static MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const std::string& titulo);
};


