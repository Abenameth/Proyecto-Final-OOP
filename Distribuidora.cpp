//
// Created by Hp on 01/12/2025.
//

#include "Distribuidora.h"
#include "Producto.h"
#include <iostream>
#include <fstream>
#include <sstream>

Distribuidora::Distribuidora():check(""),productos(),gastos(0.0){}

Distribuidora::Distribuidora(string cCheck, vector<Producto> cProductos, vector <Cliente> cClientes) {
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

void Distribuidora::vender(Cliente cliente, string p, int a) {
    if (estaProducto(p)){
        for (auto busca : this->productos) {
            if (busca.getNombre() == p) {
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

void Distribuidora::agregarProductos(const string & fichero)  {
    ifstream fich(fichero);
    if (!fich.is_open()) {
        cout << "No se abrió el fichero. " << endl;
        return;
    }
    string nombre;
    int cantidad;
    double precio;
    string linea;
    getline(fich,linea);
    while (getline(fich,linea)) {
        for (char&c:linea)
            if (c==',') c = ' ';
        stringstream ss(linea);
        ss >> nombre >> cantidad >> precio;
        productos.emplace_back(nombre,cantidad,precio);
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
    string linea;
    getline(fich,linea);
    while (getline(fich,linea)) {
        for (char&c:linea)
            if (c==',') c = ' ';
        stringstream ss(linea);
        ss >> nombre >> id >> ubicacion >> compras;
        clientes.emplace_back(nombre,id,ubicacion,compras);
    }
    fich.close();
};

void Distribuidora::productosExistentes() {
    for (auto busca : this->productos) {
        cout << busca << endl;
    }
}

void Distribuidora::mostrarClientes() {
    for (auto busca : this->clientes) {
        cout << busca << endl;
    }
}
void Distribuidora::exportarProductos() {
    ofstream fich;
    fich.open("./exportproductos.csv");
    if (!fich.is_open()) {
        cout <<"No se abrio fichero";
        return;
    }
    fich << "Nombre,Cantidad,Precio" << endl;
    for (auto busca : this->productos) {
        fich << busca.getNombre() << ","<< busca.getCantidad() << ","<< busca.getPrecio() << endl;
    }
}

void Distribuidora::exportarClientes() {
    ofstream fich;
    fich.open("./exportclientes.csv");
    if (!fich.is_open()) {
        cout <<"No se abrio fichero";
        return;
    }
    fich << "Nombre,ID,Ubicacion,Compras";
    for (auto busca : this->clientes) {
        fich << busca.getNombre() << "," <<busca.getId()<< "," << busca.getUbicacion()<< "," << busca.getCompras()<< "," << endl;
    }
}
Distribuidora::~Distribuidora() {}

