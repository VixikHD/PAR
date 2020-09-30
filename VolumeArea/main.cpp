#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void dokonciProgram() {
    cout << "\n\nNapiste cokoliv pro ukonceni programu\n";

    string hodnota;
    cin >> hodnota;

    // cin.get() 2x je taky mozny
}

void vypoctiObsahAPovrchKvadru() {
    float stranaA, stranaB, stranaC;

    cout << "Zadejte velikost strany [m] A\n";
    cin >> stranaA;
    if(cin.fail() || stranaA < 0) {
        cout << "Pouzij validni hodnotu\n";
        vypoctiObsahAPovrchKvadru();
    }

    cout << "Zadejte velikost strany B [m]\n";
    cin >> stranaB;
    if(cin.fail() || stranaB < 0) {
        cout << "Pouzij validni hodnotu\n";
        vypoctiObsahAPovrchKvadru();
    }

    cout << "Zadejte velikost strany C [m]\n";
    cin >> stranaC;
    if(cin.fail() || stranaC < 0) {
        cout << "Pouzij validni hodnotu\n";
        vypoctiObsahAPovrchKvadru();
    }

    cout << "Pocitam pro kvadr se stranami A=" << stranaA << ";B=" << stranaB << ";C=" << stranaC << "\n\n";

    float povrch = 2 * (stranaA * stranaB) + 2 * (stranaB * stranaC) + 2 * (stranaC * stranaA);
    float objem = stranaA * stranaB * stranaC;

    cout << "Povrch kvadru = " << povrch << "m^2" << endl;
    cout << "Objem kvadru = " << objem << "m^3" << endl;

    dokonciProgram();
}

void vypoctiKvadratickouRovnici() {
    float parametrA, parametrB, parametrC;

    cout << "Zadejte hodnotu A\n";
    cin >> parametrA;
    if(cin.fail()) {
        cout << "Vlozena spatna hodnota\n";
        vypoctiKvadratickouRovnici();
    }

    cout << "Zadejte hodnotu B\n";
    cin >> parametrB;
    if(cin.fail()) {
        cout << "Vlozena spatna hodnota\n";
        vypoctiKvadratickouRovnici();
    }

    cout << "Zadejte hodnotu C\n";
    cin >> parametrC;
    if(cin.fail()) {
        cout << "Vlozena spatna hodnota\n";
        vypoctiKvadratickouRovnici();
    }

    cout << "\nPocitam kvadratickou rovnici " << parametrA << "x^2 + " << parametrB << "x + " << parametrC << " = 0\n\n";

    float discriminant = (parametrB * parametrB) + (-4 * parametrA * parametrC);
    float vysledek;

    if(discriminant == 0) {
        vysledek = -parametrB / (2 * parametrA);

        cout << "Kvadraticka rovnice ma jeden koren a to X=" << vysledek;
        dokonciProgram();
        return;
    }

    if(discriminant < 0) {
        cout << "Kvadraticka rovnice nema zadny koren v mnozine realnych cisel.";
        dokonciProgram();
        return;
    }

    float sqrtDiscriminant = sqrt(discriminant);
    float vysledek2;

    vysledek = (-parametrB + sqrtDiscriminant) / (2 * parametrA);
    vysledek2 = (-parametrB - sqrtDiscriminant) / (2 * parametrA);

    cout << "Kvadraticka rovnice ma dva koreny a to X1=" << vysledek << ";X2=" << vysledek2;
    dokonciProgram();
}

void zbytecnaFunkce() {
    // Zamena dvou promenych
    int promA = 1;
    int promB = 6; // zbytecne def

    cout << "Zadejte 2 promene (int)";
    cin >> promA;
    cin >> promB;

    int j = promA;
    promA = promB;
    promB = j;

    cout << "Promene: " << promA << ";" << promB << "\n";
    // hotovo


    // Zamena tri promenych
    int a = 5;
    int b = 1; // zbytecne definovane
    int c = 3;

    cout << "Zadejte 3 promene (int)"
    cin >> a;
    cin >> b;
    cin >> c;

    int i = a;
    a = b;
    b = c;
    c = i;

    cout << "Promene: " << a << ";" << b << ";" << c << "\n";

    // Hotovo
}

int main() {
    cout << "Vyberte funkci\na : Vypocti povrch a obsah kvadru\nb : Vypocti kvadratickou rovnici\nc : Zamen hodnoty\n";

    string option;
    cin >> option;

    if(option == "a") {
        vypoctiObsahAPovrchKvadru();
    }
    else if(option == "b") {
        vypoctiKvadratickouRovnici();
    }
    else if(option == "c") {
        zbytecnaFunkce();
    }
    else {
        cout << "Pouzita spatna funkce\n";
        main();
    }

    return 0;
}
