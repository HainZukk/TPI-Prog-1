#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>

void menu(int &MenuPrincipal);

void salida(int &salir);

int funcionDado();

char decisionJugador1();

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2);

void numeroObjetivo(int &objetivo);

void mostrarDados(int v[], int cant);

void chequeoDados(int v[], int cant, int elegido, bool &chequeo);

bool eleccionDados(int acuDado, int objetivo);

void puntaje(int cant, int objetivo, int acuDado, int contElegidos, int &puntos);

void regresoMenu();

void creditos();

#endif

