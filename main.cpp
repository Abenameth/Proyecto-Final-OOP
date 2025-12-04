#include <iostream>
#include "Distribuidora.h"
using namespace std;

int main() {
    string fichero;
    Distribuidora distribuidora1;
    cout << "Ingrese el nombre del fichero de productos: ";
    cin >> fichero;
    distribuidora1.agregarProductos(fichero);
    cout << "Ingrese el nombre de fichero de cliente: ";
    cin >> fichero;
    distribuidora1.agregarClientes(fichero);
    int opcion = 0;
    string opcionStr = "";
    while (opcion != 8) {
        cout << "MENU"<<endl;
        cout << "1-Abastecer"<<endl;
        cout << "2-Vender"<<endl;
        cout << "3-Agregar producto"<<endl;
        cout << "4-Agregar clientes "<<endl;
        cout << "5-Mostrar clientes"<<endl;
        cout << "6-Mostrar productos"<<endl;
        cout << "7-Exportar productos"<<endl;
        cout << "8-Exportar clientes"<<endl;
        cout << "9-Salir"<<endl;
        cin >> opcionStr;
        try {
            opcion = stoi(opcionStr);
        } catch (...) {
            opcion = 0;
        }
        switch (opcion) {
            case 1: {
                string nombre;
                int cantidad;
                cout << "Escribe nombre de producto"<<endl;
                cin >> nombre;
                cout << "Escribe la cantidad de producto a abastecer";
                cin >> cantidad;
                distribuidora1.abastecer(nombre,cantidad);
                break;
            }
            case 2: {
                string c, p;
                int a;
                cout << "ingrese el nombre del cliente"<<endl;
                cin >> c;
                cout <<"ingresa el nombre del producto"<<endl;
                cin>>p;
                cout <<"ingresa el numero de producto a vender"<<endl;
                cin >> a;
                distribuidora1.vender(c,p,a);
                break;

            }
            case 3: {
                string nombre;
                int cantidad;
                double precio;
                cout << "ingresa el nombre"<<endl;
                cin >> nombre;
                cout <<"ingresa la cantidad de productos"<<endl;
                cin >> cantidad;
                cout <<"ingresa el precio de cada producto"<<endl;
                cin >>precio;
                distribuidora1.agregarProducto(nombre,cantidad,precio);
                break;
            }
            case 4: {
                string nombre,id,ubi;
                int numero;
                cout << "ingresa el nombre"<<endl;
                cin >> nombre;
                cout <<"ingresa el ID"<<endl;
                cin >> id;
                cout <<"ingresa ubicacion"<<endl;
                cin >>ubi;
                cout <<"ingresa numero de compras"<<endl;
                cin >>numero;
                distribuidora1.agregarCliente(nombre,id,ubi,numero);
                break;
            }
            case 5: {
                distribuidora1.mostrarClientes();
                break;
            }
            case 6: {
                distribuidora1.productosExistentes();
                break;
            }
            case 7: {
                distribuidora1.exportarProductos();
                break;
            }
            case 8: {
               distribuidora1.exportarClientes();
                break;
            }
            case 9: {
                cout <<"Salir"<<endl;
                break;
            }
            default: {
                cout << "Opcion invalida"<<endl;
                break;
            }
        }
    }
    return 0;
}