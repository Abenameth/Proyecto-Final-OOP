//
// Created by Hp on 01/12/2025.
//

#include "Distribuidora.h"
#include "Producto.h"

Distribuidora::Distribuidora():check(""),productos(),gastos(0.0){}

Distribuidora::Distribuidora(string cCheck, vector<Producto> cProductos) {
    this->check = cCheck;
    this->productos = cProductos;
}

double Distribuidora::getGastos() {
    return gastos;
}

bool Distribuidora::estaproducto(Producto producto) {
    for (auto busca : this->productos) {
        if (busca.getNombre() == producto.getNombre()) {
            return true;
        }
        else {
            return false;
        }
    }

}

void Distribuidora::abastecer(Producto producto) {
    if (estaproducto(producto) == true) {
    for (auto busca : this->productos) {
        if (busca.getNombre() == producto.getNombre() && producto.valortotal() < capital) {
            busca.setCantidad(busca.getCantidad() + producto.getCantidad());
            capital = capital - producto.valortotal();
            gastos = gastos + producto.valortotal();
        }
        else if (busca.getNombre() == producto.getNombre() && producto.valortotal() > capital) {
            cout << "dinero insuficiente para abastecer"<<endl;
        }
    }
    }
    else {
        cout << "Este producto no existe debe de añadirlo"<< endl;
    }
}

void Distribuidora::vender(Producto producto) {
    if (estaproducto(producto)== true) {
        for (auto busca : this->productos) {
            if (busca.getNombre() == producto.getNombre()) {
                if (busca.getCantidad()<producto.getCantidad()) {
                    cout <<"No hay tanto producto para vender" << endl;
                }
                else {
                    busca.setCantidad(busca.getCantidad() - producto.getCantidad());
                    capital = capital + producto.valortotal();
                }
            }
        }
    }
    else {
        cout << "Este producto no existe, debe de añadirlo"<< endl;
    }
}

void Distribuidora::agregarproducto(Producto producto)  {
    productos.push_back(producto);
}
void Distribuidora::Productosexistentes() {
    for (auto busca : this->productos) {
        cout << busca.getNombre() << " | ";
    }
}
Distribuidora::~Distribuidora() {}

