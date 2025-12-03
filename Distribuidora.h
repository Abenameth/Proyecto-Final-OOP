//
// Created by Hp on 01/12/2025.
//

#ifndef UNTITLED28_DISTRIBUIDORA_H
#define UNTITLED28_DISTRIBUIDORA_H
#include <string>
#include <vector>
#include "Producto.h"
#include <iostream>

using namespace std;

class Distribuidora {
private:
    string check;
    vector<Producto> productos;
    double gastos;
    double capital = 10000.0;

public:
    Distribuidora();
    Distribuidora(string cCheck, vector<Producto> cProductos);

    double getGastos();

    void abastecer(Producto producto);
    void vender(Producto producto);
    bool estaproducto(Producto producto);
    void agregarproducto(Producto producto);
    void Productosexistentes();

    friend ostream & operator<<(ostream &os, const Distribuidora &d);
    ~Distribuidora();
};


#endif //UNTITLED28_DISTRIBUIDORA_H