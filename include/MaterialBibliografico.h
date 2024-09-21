#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H

#include <string>

class MaterialBibliografico {
protected:
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool estaPrestado;

public:
    MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor);
    
    virtual void mostrarInformacion() const = 0; // Método virtual puro

    std::string getNombre() const { return nombre; }
    bool isPrestado() const { return estaPrestado; }
    void setPrestado(bool prestado) { estaPrestado = prestado; }
};

#endif // MATERIALBIBLIOGRAFICO_H





