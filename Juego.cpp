#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

const int MAX_DADOS = 12;

int main() {
    string jugadorMax;
    int puntosMax = 0;
    int RONDAS = 3;
    srand(time(NULL));

    while (true) {
        int MenuPrincipal;
        menu(MenuPrincipal);
        system("cls");

        switch (MenuPrincipal) {
            case 0: {
                int salir;
                salida(salir);
                if (salir == 0) {
                    cout << endl << "Usted decidio salir del juego" << endl;
                    return 0;
                } else {
                    cout << endl << "Usted decidio continuar en el juego" << endl << endl;
                }
                break;
            }

            case 1: {
                cout << "-----" << endl << "JUGAR" << endl << "-----" << endl;

                string jugadorA, jugadorB, jugador1, jugador2;
                cout << endl << "Nombre del jugador A: ";
                cin >> jugadorA;
                cout << "Nombre del jugador B: ";
                cin >> jugadorB;
                cout << endl << "--------------------------------------------------------" << endl << endl;
                char ganador = decisionJugador1();

                if (ganador == 'A') {
                    cout << "Gana " << jugadorA << endl;
                    jugador1 = jugadorA;
                    jugador2 = jugadorB;
                } else {
                    cout << "Gana " << jugadorB << endl;
                    jugador1 = jugadorB;
                    jugador2 = jugadorA;
                }

                cout << "El jugador 1 es: " << jugador1 << endl;
                cout << "El jugador 2 es: " << jugador2 << endl << endl;
                cout << "--------------------------------------------------------" << endl << endl;

                int rondaActual = 1;
                int dadosStock1 = 6, dadosStock2 = 6;
                int puntosJ1 = 0, puntosJ2 = 0;

                while (rondaActual <= RONDAS && dadosStock1 != 0 && dadosStock2 != 0) {
                    for (int i = 1; i <= 2; i++) {
                        mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
                        cout << "--------------------------------------------------------" << endl << endl;

                        cout << "Turno del jugador " << i << ": ";
                        if (i == 1) {
                            cout << jugador1 << endl << endl;
                        } else {
                            cout << jugador2 << endl << endl;
                        }

                        int objetivo;
                        numeroObjetivo(objetivo);
                        cout << "--------------------------------------------------------" << endl << endl;

                        int vDadosStock1[MAX_DADOS] = {0};
                        int vDadosStock2[MAX_DADOS] = {0};

                        cout << "Tirada de dados: " << endl << endl;

                        if (i == 1) {
                            mostrarDados(vDadosStock1, dadosStock1);
                        } else {
                            mostrarDados(vDadosStock2, dadosStock2);
                        }

                        cout << endl << endl << "--------------------------------------------------------" << endl << endl;

                        int acuDado = 0, contElegidos = 0, dadoElegido = 0;
                        bool eleccion = false, chequeo = false;

                        while (!eleccion) {
                            cout << "Elija los dados para llegar al numero objetivo (O presione 0 para terminar la jugada): ";
                            cin >> dadoElegido;

                            if (dadoElegido == 0) {
                                eleccion = true;
                                cout << "La ronda ha sido finalizada como no exitosa." << endl;
                                break;
                            }

                            if (i == 1) {
                                chequeoDados(vDadosStock1, dadosStock1, dadoElegido, chequeo);
                            } else {
                                chequeoDados(vDadosStock2, dadosStock2, dadoElegido, chequeo);
                            }

                            if (chequeo) {
                                contElegidos++;
                                acuDado += dadoElegido;
                            } else {
                                cout << "Dado no valido. Intente de nuevo." << endl;
                            }

                            if (i == 1 && contElegidos == dadosStock1) {
                                cout << "Ya has elegido todos los dados disponibles. No puedes seleccionar más." << endl;
                                eleccion = true;
                                break;
                            } else if (i == 2 && contElegidos == dadosStock2) {
                                cout << "Ya has elegido todos los dados disponibles. No puedes seleccionar mas." << endl;
                                eleccion = true;
                                break;
                            }

                            if (!eleccion) {
                                eleccion = eleccionDados(acuDado, objetivo);
                            }
                        }

                        cout << endl << "--------------------------------------------------------" << endl << endl;

                        if (objetivo == acuDado) {
                            if (i == 1) {
                                dadosStock1 -= contElegidos;
                                dadosStock2 += contElegidos;
                            } else {
                                dadosStock2 -= contElegidos;
                                dadosStock1 += contElegidos;
                            }
                        } else {
                            if (i == 1 && dadosStock2 > 1) {
                                dadosStock1 += 1;
                                dadosStock2 -= 1;
                            } else if (i == 2 && dadosStock1 > 1) {
                                dadosStock2 += 1;
                                dadosStock1 -= 1;
                            }
                        }

                        if (i == 1) {
                            puntaje(dadosStock1, objetivo, acuDado, contElegidos, puntosJ1);
                        } else {
                            puntaje(dadosStock2, objetivo, acuDado, contElegidos, puntosJ2);
                        }

                        if (objetivo == acuDado) {
                            cout << "La cantidad de dados elegida fue de " << contElegidos << " dados, y la suma total " << endl;
                            cout << "de los dados fue de " << acuDado << ", por lo que el puntaje total, que se obtiene " << endl;
                            cout << "de la multiplicacion de estos valores, sera de " << contElegidos * acuDado << " puntos." << endl << endl;
                        }

                        if (dadosStock2 == 0 || dadosStock1 == 0) {
                            i = 3;
                        }
                    }
                    rondaActual++;
                }

                cout << "***--------------------------------------------------***" << endl << endl;

                cout << "Los puntajes finales de la partida son: " << endl;
                if (puntosJ1 > puntosJ2) {
                    cout << "El ganador es el Jugador 1: " << jugador1 << " con " << puntosJ1 << " puntos." << endl << endl;
                    if (puntosJ1 > puntosMax) {
                        puntosMax = puntosJ1;
                        jugadorMax = jugador1;
                    }
                } else if (puntosJ1 == puntosJ2) {
                    cout << "La partida termino empatada en " << puntosJ1 << " puntos." << endl << endl;
                } else {
                    cout << "El ganador es el Jugador 2: " << jugador2 << " con " << puntosJ2 << " puntos." << endl << endl;
                    if (puntosJ2 > puntosMax) {
                        puntosMax = puntosJ2;
                        jugadorMax = jugador2;
                    }
                }

                regresoMenu();
                system("cls");
                break;
            }

            case 2: {
                cout << "ESTADISTICAS" << endl << endl;
                if (puntosMax == 0) {
                    cout << "No hay registro de partidas jugadas" << endl << endl;
                } else {
                    cout << "El puntaje maximo obtenido le pertenece al jugador "
                         << jugadorMax << " y es de " << puntosMax << endl << endl;
                }
                regresoMenu();
                system("cls");
                break;
            }

            case 3: {
                creditos();
                regresoMenu();
                system("cls");
                break;
            }

            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }

    return 0;
}
