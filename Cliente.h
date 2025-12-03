//
// Created by Abenameth on 03/12/2025.
//

#ifndef PROYECTO_FINAL_OOP_CLIENTE_H
#define PROYECTO_FINAL_OOP_CLIENTE_H
#include <string>
#include<iostream>
using namespace std;

class Cliente {
private:
    string nombre;
    string id;
    string ubicacion;
    int compras;
public:
    Cliente();
    Cliente(string cNombre,string cId, string cUbicacion, int cCompras);\
    string getNombre();
    string getId();
    string getUbicacion();
    int getCompras();
    void setNombre(string cNombre);
    void setUbicacion(string cUbicacion);
    void compraRealizada();
    friend ostream& operator <<(ostream &os,const Cliente &obj);
    ~Cliente();
};


#endif //PROYECTO_FINAL_OOP_CLIENTE_H