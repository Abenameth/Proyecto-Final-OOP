//
// Created by Hp on 01/12/2025.
//

#ifndef UNTITLED28_DISTRIBUIDORA_H
#define UNTITLED28_DISTRIBUIDORA_H
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include <iostream>

using namespace std;

class Distribuidora {
private:
    string check;
    vector<Producto> productos;
    vector<Cliente> clientes;
    double gastos;
    double capital = 10000.0;

public:
    Distribuidora();
    Distribuidora(string cCheck, vector<Producto> cProductos, vector<Cliente> cClientes);

    double getGastos();

    void abastecer(Producto b, int a);
    void vender(Cliente cliente, string p, int a);
    bool estaProducto(string nombre);
    void agregarProductos(const string& Fichero);
    void agregarClientes(const string& Fichero);
    void productosExistentes();
    void mostrarClientes();

    friend ostream & operator<<(ostream &os, const Distribuidora &d);
    ~Distribuidora();
};


#endif //UNTITLED28_DISTRIBUIDORA_H