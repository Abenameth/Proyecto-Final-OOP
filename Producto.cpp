//
// Created by Hp on 01/12/2025.
//

#include "Producto.h"

Producto::Producto() {
    nombre = "";
    cantidad = 0;
    precio = 0.0;
}

Producto::Producto(string cNombre, int cCantidad, double cPrecio):
    nombre(cNombre), cantidad(cCantidad),precio(cPrecio){}

string Producto::getNombre() {
    return nombre;
}

int Producto::getCantidad() {
    return cantidad;
}

double Producto::getPrecio() {
    return precio;
}

void Producto::setNombre(string n) {
    nombre = n;
}

void Producto::setCantidad(int c) {
    cantidad = c;
}

void Producto::setPrecio(double p) {
    precio = p;
}

ostream & operator<<(ostream &os, const Producto &d) {
    os << "Nombre del producto: " << d.nombre << endl;
    os << "Cantidad del producto: " << d.cantidad << endl;
    os << "Precio del producto: " << d.precio << endl;
    return os;
}

double Producto::valortotal() {
    return cantidad * precio;
}
Producto::~Producto() {

}

