//
// Created by Hp on 01/12/2025.
//

#ifndef UNTITLED28_PRODUCTO_H
#define UNTITLED28_PRODUCTO_H
#include <string>
#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    int cantidad;
    double precio;

public:
    Producto();
    Producto(string cNombre, int cCantidad, double cPrecio);

    string getNombre();
    int getCantidad();
    double getPrecio();

    void setNombre(string n);
    void setCantidad(int c);
    void setPrecio(double p);
    double valortotal();

    friend ostream & operator<<(ostream &os, const Producto &d);

    ~Producto();

};


#endif //UNTITLED28_PRODUCTO_H