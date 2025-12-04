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
    vector<Producto> productos;
    vector<Cliente> clientes;
    double gastos;
    double capital = 10000.0;

public:
    Distribuidora();
    Distribuidora(vector<Producto> cProductos, vector<Cliente> cClientes);

    double getGastos();

    void abastecer(string b, int a);
    void vender(string c, string p, int a);
    bool estaProducto(string nombre);
    bool estaCliente(string nombre);
    void agregarProductos(const string& Fichero);
    void agregarClientes(const string& Fichero);
    void agregarProducto(string cNombre, int cCantidad, double cPrecio);
    void agregarCliente(string cNombre, string cId, string cUbicacion, int cCompras);
    void productosExistentes();
    void mostrarClientes();
    void exportarProductos();
    void exportarClientes();

    friend ostream & operator<<(ostream &os, const Distribuidora &d);
    ~Distribuidora();
};


#endif //UNTITLED28_DISTRIBUIDORA_H