#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void salida(int &salir) {
    cout << "SALIR" << endl << endl;
    cout << "Esta seguro que desea salir del juego?" << endl;
    cout << "Presione 0 para salir y 1 para volver al Menu Principal: ";
    cin >> salir;
    while (salir != 0 && salir != 1) {
        cout << "La opcion no es correcta, pruebe otra vez" << endl;
        cout << "Presione 0 para salir y 1 para permanecer en el juego" << endl;
        cin >> salir;
    }
}

int funcionDado() {
    return rand() % 6 + 1;
}

char decisionJugador1() {
    int dadoA, dadoB;
    dadoA = funcionDado();
    dadoB = funcionDado();
    while (dadoA == dadoB) {
        dadoB = funcionDado();
    }
    cout << "Jugador A tira: " << dadoA << endl;
    system("pause");
    cout << "Jugador B tira: " << dadoB << endl;
    system("pause");
    if (dadoA > dadoB) {
        cout << "Jugador A comienza la partida." << endl;
        system("cls");
        return 'A';
    } else {
        cout << "Jugador B comienza la partida." << endl;
        system("cls");
        return 'B';
    }
}

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2) {
    cout << "Ronda actual: " << rondaActual << endl;
    cout << "Puntaje jugador 1: " << puntosJ1 << endl;
    cout << "Puntaje jugador 2: " << puntosJ2 << endl;
    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
    cout << "Dados Stock jugador 2: " << dadosStock2 << endl << endl;
}

void numeroObjetivo(int &objetivo) {
    int dado12A, dado12B;
    dado12A = rand() % 12 + 1;
    dado12B = rand() % 12 + 1;
    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
    objetivo = dado12A + dado12B;
    cout << "El numero objetivo es: " << objetivo << endl << endl;
}

void mostrarDados(int v[], int cant) {
    int dado;
    for (int i = 0; i < cant; i++) {
        dado = funcionDado();
        v[i] = dado;
        cout << v[i] << " - ";
    }
}

void chequeoDados(int v[], int cant, int elegido, bool &chequeo) {
    chequeo = false;
    for (int i = 0; i < cant; i++) {
        if (elegido == v[i]) {
            chequeo = true;
            v[i] = 0;
            return;
        }
    }
    if (!chequeo) {
        cout << "El numero elegido no esta entre los dados tirados." << endl;
    }
}

bool eleccionDados(int acuDado, int objetivo) {
    if (acuDado == objetivo) {
        return true;
    } else if (acuDado > objetivo) {
        cout << endl << "--------------------------------------------------------" << endl;
        cout << endl << "La suma de los dados seleccionados supera al numero objetivo" << endl;
        return true;
    }
    return false;
}

void puntaje(int cant, int objetivo, int acuDado, int contElegidos, int &puntos) {
    if (objetivo == acuDado && cant != 0) {
        cout << "Jugada exitosa!" << endl;
        cout << "Pasan al siguiente jugador " << contElegidos << " dados!" << endl << endl;
        puntos += objetivo * contElegidos;
    } else if (objetivo != acuDado) {
        cout << "Jugada no exitosa" << endl;
        cout << "Como penalizacion, recibira un dado de su rival" << endl;
        cout << "Solamente si este tiene mas de uno" << endl;
        cout << endl << "--------------------------------------------------------" << endl << endl;
    } else if (objetivo == acuDado && cant == 0) {
        cout << "No tiene mas dados! Ha ganado la partida!!" << endl << endl;
        puntos += (objetivo * contElegidos) + 10000;
    }
}

void regresoMenu() {
    cout << "Presione cualquier tecla para volver al Menu Principal..." << endl;
    system("pause");
}


void creditos() {
    cout << "CREDITOS" << endl << endl;
    cout << "Los integrantes del equipo son:" << endl;
    cout << "-Equipo 26- " << endl;
    cout << "Legajo: 31924 - Tiago Alexis Fernandez Moschen " << endl;
    cout << "Legajo: 32580 - Tobias Marcelo Nguyen " << endl;
    cout << "   - " << endl << endl;
}
