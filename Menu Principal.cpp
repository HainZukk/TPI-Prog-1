#include <iostream>
using namespace std;

void menu(int &MenuPrincipal) {
    cout << "ENFRENDADOS" << endl;
    cout << "------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "------------------" << endl;
    cout << "0 - SALIR" << endl << endl;
    cout << "Ingrese la opcion que desee: ";
    cin >> MenuPrincipal;
    cout << endl;

    while (MenuPrincipal < 0 || MenuPrincipal > 3) {
        cout << "La opcion ingresada es invalida. Por favor, pruebe otra vez" << endl;
        cin >> MenuPrincipal;
    }
}
