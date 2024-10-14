#pragma once
#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;  
    std::string isbn;    
    std::string autor;   
    bool prestado=false;      

public:
    // Constructor 
    MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor);

    //  verificar si el material está prestado
    bool estaPrestado() const;

    // prestar y devolver el material
    void prestar();
    void devolver();

    //  mostrar la información del material
    virtual void mostrarInformacion() const = 0;

    // Getter 
    std::string getNombre() const;

    // buscar un material en la biblioteca
    static MaterialBibliografico* buscarMaterial(MaterialBibliografico* biblioteca[], int numMateriales, const std::string& titulo);
};


