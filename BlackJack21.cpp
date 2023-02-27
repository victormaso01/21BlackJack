#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

int treboles[12];
int picas[12];
int corazones[12];
int diamantes[12];
int valRand;
int conteoJ1 = 0;
int conteoCrup = 0;

string paloCarta;
string nombrePlayer;
string croupiere = "croupiere";

bool rendicion1 = false;
bool rendicion2 = false;
bool ganador1 = false;
bool ganador2 = false;
bool perdedor1 = false;
bool perdedor2 = false;

void inisioCartas(int(&pArray)[12]) {
    for (int i = 0; i < 12; i++)
    {
        pArray[i] = 1;
    }
    // for (int i = 0; i < 12; i++)
    // {
    //     cout << pArray[i];
    // }

}

void inisio() {
    cout << "===========================================================================" << endl;
    cout << "=                               21 BLACK JACK                             =" << endl;
    cout << "=                                Bienvenido                               =" << endl;
    cout << "===========================================================================" << endl;
    cout << "Bienvenido a la mesa, antes de empezar, escriba su nombre" << endl;
    cin >> nombrePlayer;
    cout << "Bienvenido " << nombrePlayer << " vamos a empezar." << endl;
}

bool chequeoPuntos(int& puntos, bool& winner, bool& loser) {
    if (puntos == 21) {
        winner = true;
        return true;
    }
    else if (puntos > 21) {
        loser = true;
        return true;

    }
    return false;
}

bool chequeoGanador(int points, int points2, bool& winner2) {
    if (points2 > points) {
        winner2 = true;
        return true;
    }
    else {
        return false;
    }

}

static void reparto(int& conteo, string player) {
    bool escogido = true;
    int posCarta = 0;
    int valorPalo;


    do {
        posCarta = rand() % 12;
        valorPalo = rand() % 3;

        if ((valorPalo == 1) && (picas[posCarta] == 1)) {

            picas[posCarta] = 0;
            paloCarta = "picas";
            escogido = true;

            //cout << posCarta;
            //cout << valorPalo;
            //cout << paloCarta;
            //cout << escogido;

        }


        else if ((valorPalo == 2) && (treboles[posCarta] == 1)) {

            picas[posCarta] = 0;
            paloCarta = "treboles";
            escogido = true;

            //cout << posCarta;
            //cout << valorPalo;
            //cout << paloCarta;
            //cout << escogido;
        }



        if ((valorPalo == 3) && (diamantes[posCarta] == 1)) {

            picas[posCarta] = 0;
            paloCarta = "diamantes";
            escogido = true;

            // cout << posCarta;
            // cout << valorPalo;
            // cout << paloCarta;
            // cout << escogido;

        }


        if ((valorPalo == 0) && (corazones[posCarta] == 1)) {

            picas[posCarta] = 0;
            paloCarta = "corazones";
            escogido = true;

            //cout << posCarta;
            //cout << valorPalo;
            //cout << paloCarta;
            //cout << escogido;

        }


    } while (!escogido);

    if (posCarta == 0) {
        cout << "La carta es un As de " << paloCarta << " ." << endl;
        if (conteo + 11 > 21) {
            conteo += 1;
        }
        else {
            if (player == nombrePlayer) {
                cout << "Quieres que esta carta valga  1 u 11?" << endl;
                cout << " [1]   [11]  " << endl;
                int election;
                cin >> election;
                if (election == 1) {
                    conteo += 1;
                }
                else if (election == 11) {
                    conteo += 11;
                }
                else {
                    cout << "Opcion no permitida." << endl;

                }
            }
            else {
                if ((rand() % 2) == 0) {
                    conteo += 11;
                }
                else {
                    conteo += 1;
                }
            }
        }


    }
    else if (posCarta >= 10) {
        conteo += 10;
        if (posCarta == 10) {
            cout << player << ": La carta es la J de " << paloCarta << endl;
        }
        else if (posCarta == 11) {
            cout << player << ": La carta es la Q de " << paloCarta << endl;
        }
        else if (posCarta == 12) {
            cout << player << ": La carta es la K de " << paloCarta << endl;
        }
    }
    else {

        cout << player << ": La carta es el " << posCarta + 1 << " de " << paloCarta << endl;
        conteo += posCarta + 1;
    }
}

bool continuacion(string quienjuega, int puntosConteo) {
    int eleccion = 0;
    cout << quienjuega << ": tienes " << puntosConteo << " puntos. Quieres volver a jugar?" << endl;

    while ((eleccion != 1) && (eleccion != 2)) {
         
            cout << "[1].Yes    [2].No" << endl;
            cin >> eleccion;
            if ((eleccion != 1) && (eleccion != 2)) {
                cout << "Por favor elige otra opción" << endl;
            }

        if (eleccion == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    srand(time(NULL));

    inisio();

    inisioCartas(diamantes);
    inisioCartas(corazones);
    inisioCartas(treboles);
    inisioCartas(picas);

    reparto(conteoJ1, nombrePlayer);
    Sleep(2500);
    reparto(conteoJ1, nombrePlayer);
    Sleep(2500);

    cout << "Puntos " << nombrePlayer << ": " << conteoJ1 << endl;
    rendicion1 = chequeoPuntos(conteoJ1, ganador1, perdedor1);
    Sleep(2500);
    reparto(conteoCrup, croupiere);
    Sleep(2500);
    cout << "Puntos " << croupiere << ": " << conteoCrup << endl;

    while (!rendicion1) {
        if (continuacion(nombrePlayer, conteoJ1)) {
            reparto(conteoJ1, nombrePlayer);
            cout << "Puntos " << nombrePlayer << ": " << conteoJ1 << endl;
            rendicion1 = chequeoPuntos(conteoJ1, ganador1, perdedor1);
        }
        else {
            rendicion1 = true;
        }

    }
    if (ganador1) {
        cout << nombrePlayer << " es el campeon y la banca pierde." << endl;

    }
    else if (perdedor1) {
        cout << nombrePlayer << " ha perdido. La banca siempre gana." << endl;
    }
    else {
        while (!rendicion2) {
            reparto(conteoCrup, croupiere);
            Sleep(2500);
            cout << "Puntos " << croupiere << ": " << conteoCrup << endl;
            rendicion2 = chequeoPuntos(conteoCrup, ganador2, perdedor2);
            if (!rendicion2) {
                rendicion2 = chequeoGanador(conteoJ1, conteoCrup, ganador2);
            }
        }
        if (ganador2) {
            cout << nombrePlayer << " ha perdido. La banca siempre gana." << endl;
        }
        else if (perdedor2) {
            cout << nombrePlayer << " es el campeon y la banca pierde." << endl;
        }
    }

}




