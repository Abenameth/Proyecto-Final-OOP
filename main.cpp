#include <iostream>
#include "Distribuidora.h"
using namespace std;

int main() {
    string fichero;
    cout << "Ingrese el nombre del fichero de productos: ";
    cin >> fichero;
    cout << "Ingrese el nombre de fichero de cliente: ";
    cin >> fichero;
    int opcion = 0;
    while (opcion != 8) {
        cout << "MENU"<<endl;
        cout << "1-Abastecer"<<endl;
        cout << "2-vender"<<endl;
        cout << "3-Agregar producto"<<endl;
        cout << "4-Agregar clientes "<<endl;
        cout << "5-mostrar clientes"<<endl;
        cout << "6-exportar productos"<<endl;
        cout << "7-exportar clientes"<<endl;
        cout << "8-salir del programa"<<endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int cantidad;
                cout << "Escribe nombre de producto"<<endl;
                cin >> nombre;
                cout << "Escribe la cantidad de producto a abastecer";
                break;
            }
            case 2: {
                break;

            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                cout << "Salir"<<endl;
                break;
            }
            default: {
                cout << "Opcion no valida"<<endl;
            }
        }
    }
    return 0;
}