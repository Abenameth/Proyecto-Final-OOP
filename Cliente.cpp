//
// Created by Abenameth on 03/12/2025.
//

#include "Cliente.h"
Cliente::Cliente() {
    this->nombre = " ";
    id = " ";
    ubicacion = " ";
    compras = 0;
}

Cliente::Cliente(string cNombre, string cId, string cUbicacion, int cCompras) {
    this->nombre = cNombre;
    id = cId;
    ubicacion = cUbicacion;
    compras = cCompras;
}

string Cliente::getNombre() {
    return this->nombre;
}

string Cliente::getId() {
    return id;
}

string Cliente::getUbicacion() {
    return ubicacion;
}

int Cliente::getCompras() {
    return compras;
}

void Cliente::setNombre(string cNombre) {
    this->nombre = cNombre;
}

void Cliente::setUbicacion(string cUbicacion) {
    ubicacion = cUbicacion;
}

void Cliente::compraRealizada() {
    compras += 1;
}

ostream &operator<<(ostream &os, const Cliente &obj) {
    os << "Cliente " << obj.id << "\n Nombre: " << obj.nombre << "\n Ubicacion: " << obj.ubicacion <<
            "\n Numero de compras: " << obj.compras;
}

Cliente::~Cliente(){}