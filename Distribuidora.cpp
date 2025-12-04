//
// Created by Hp on 01/12/2025.
//

#include "Distribuidora.h"
#include "Producto.h"
#include <iostream>
#include <fstream>
#include <sstream>


Distribuidora::Distribuidora():productos(),gastos(0.0){}

Distribuidora::Distribuidora(vector<Producto> cProductos, vector <Cliente> cClientes) {
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

bool Distribuidora::estaCliente(string name) {
    for (auto&e:clientes) {
        if (name == e.getNombre())return true;
    }
    return false;
}

void Distribuidora::abastecer(string a, int b) {
    if (estaProducto(a)) {
    for (auto &busca : this->productos) {
        if (busca.getNombre() == a && (busca.getPrecio() * b) < capital) {
            busca.setCantidad(busca.getCantidad() + b);
            capital -= busca.getPrecio() * b;
            gastos += busca.getPrecio() * b;
        }
        else if (busca.getNombre() == a && (b * busca.getPrecio())> capital) {
            cout << "dinero insuficiente para abastecer"<<endl;
        }
    }
    }
    else {
        cout << "Este producto no existe debe de añadirlo"<< endl;
    }
}

void Distribuidora::vender(string c, string p, int a) {
    if (estaProducto(p)&& estaCliente(c)){
        for (auto & busca : this->productos) {
            if (busca.getNombre() == p) {
                if (busca.getCantidad() < a ) {
                    cout <<"No hay tanto producto para vender" << endl;
                }
                else {
                    capital += a*busca.getPrecio();
                    busca.setCantidad(busca.getCantidad() - a);
                    cout << "Venta realizada" << endl;
                }
            }
        }
        for (auto & cliente : this->clientes) {
            if (cliente.getNombre() == c) {
                cliente.compraRealizada();
                break;
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
    if (fich.peek() == ifstream::traits_type::eof()) {
        cout << "El archivo está vacío o no tiene el formato adecuado" << endl;
        return;
    }
    string nombre;
    int cantidad;
    double precio;
    string linea;
    getline(fich,linea);
    while (getline(fich,linea)) {
        if (linea.empty()) continue;
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
        exit(1);
    }
    if (fich.peek() == ifstream::traits_type::eof()) {
        cout << "El archivo está vacío o no tiene el formato adecuado" << endl;
        exit(2);
    }
    string nombre,id,ubicacion;
    int compras;
    string linea;
    getline(fich,linea);
    while (getline(fich,linea)) {
        if (linea.empty()) continue;
        for (char&c:linea)
            if (c==',') c = ' ';
        stringstream ss(linea);
        if (!(ss >> nombre >> id >> ubicacion >> compras)) {
            cout << "Error en formato del archivo." << endl;
            exit(3);
        };
        clientes.emplace_back(nombre,id,ubicacion,compras);
    }
    fich.close();
};

void Distribuidora::agregarProducto(string cNombre, int cCantidad, double cPrecio) {
    productos.emplace_back(cNombre,cCantidad,cPrecio);
}

void Distribuidora::agregarCliente(string cNombre, string cId, string cUbicacion, int cCompras) {
    clientes.emplace_back(cNombre,cId,cUbicacion,cCompras);
}

void Distribuidora::productosExistentes() {
    for (const auto &busca : this->productos) {
        cout << busca << endl;
    }
}

void Distribuidora::mostrarClientes() {
    for (const auto &busca : this->clientes) {
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
    for (auto &busca : this->productos) {
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
    fich << "Nombre,ID,Ubicacion,Compras"<<endl;
    for (auto & busca : this->clientes) {
        fich << busca.getNombre() << "," <<busca.getId()<< "," << busca.getUbicacion()<< "," << busca.getCompras()<< endl;
    }
}

ostream & operator<<(ostream &os, const Distribuidora &d) {
    os << "Capital disponible: " << d.capital << endl;
    os << "Gastos acumulados:  " << d.gastos << endl;
    return os;
}
Distribuidora::~Distribuidora() {}

