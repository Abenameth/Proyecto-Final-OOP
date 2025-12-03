//
// Created by Hp on 01/12/2025.
//

#include "Distribuidora.h"
#include "Producto.h"
#include <iostream>
#include <fstream>

Distribuidora::Distribuidora():check(""),productos(),gastos(0.0){}

Distribuidora::Distribuidora(string cCheck, vector<Producto> cProductos, vector <Clientes> cClientes) {
    this->check = cCheck;
    this->productos = cProductos;
    this ->clientes = cClientes;
}

double Distribuidora::getGastos() {
    return gastos;
}

bool Distribuidora::estaProducto(string name) {
    for (auto&e:productos) {
        if (name == e.getNombre())return true;
    }
    return false;
}

void Distribuidora::abastecer(Producto a, int b) {
    if (estaProducto(a.getNombre()) == true) {
    for (auto &busca : this->productos) {
        busca.setCantidad(busca.getCantidad() + b);
        if (busca.getNombre() == a.getNombre() && busca.valortotal() < capital) {

            capital = capital - busca.valortotal();
            gastos = gastos + busca.valortotal();
        }
        else if (busca.getNombre() == a.getNombre() && busca.valortotal() > capital) {
            cout << "dinero insuficiente para abastecer"<<endl;
        }
    }
    }
    else {
        cout << "Este producto no existe debe de añadirlo"<< endl;
    }
}

void Distribuidora::vender(Cliente cliente, Producto p, int a) {
    if (estaProducto(p.getNombre())== true) {
        for (auto busca : this->productos) {
            if (busca.getNombre() == p.getNombre()) {
                if (busca.getCantidad() < a ) {
                    cout <<"No hay tanto producto para vender" << endl;
                }
                else {
                    busca.setCantidad(busca.getCantidad() - a);
                    capital += busca.valortotal();
                    cliente.compraRealizada();
                    cout << "Venta realizada" << endl;
                }
            }
        }
    }
    else {
        cout << "Este producto no existe, debe de añadirlo"<< endl;
    }
}

void Distribuidora::agregarProducto(const string & fichero)  {
    ifstream fich(fichero);
    if (!fich.is_open()) {
        cout << "No se abrió el fichero. " << endl;
        return;
    }
    string nombre;
    int cantidad;
    double precio;
    while (fich >> nombre >> cantidad >> precio) {
        Producto p(nombre,cantidad,precio);
        productos.push_back(p);
    }
    fich.close();
};

void Distribuidora::agregarClientes(const string & fichero)  {
    ifstream fich(fichero);
    if (!fich.is_open()) {
        cout << "No se abrió el fichero. " << endl;
        return;
    }
    string nombre,id,ubicacion;
    int compras;
    while (fich >> nombre >> id >> ubicacion >> compras) {
        Cliente c(nombre,id,ubicacion,compras);
        clientes.push_back(c);
    }
    fich.close();
};

void Distribuidora::productosExistentes() {
    for (auto busca : this->productos) {
        cout << busca.getNombre() << " | ";
    }
}
Distribuidora::~Distribuidora() {}

