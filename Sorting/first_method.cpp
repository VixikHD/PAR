#include <iostream>
#include "cstdlib"

void validateInput();
void finishProgram();

using namespace std;

int main() {
    cout << "Razeni cisel s pomocnou bunkou:\n\n";
    int a,b,c,i;

    cout << "Zadejte A:\n";
    cin >> a;
    validateInput();

    cout << "Zadejte B:\n";
    cin >> b;
    validateInput();

    cout << "Zadejte C:\n";
    cin >> c;
    validateInput();

    if(a > b) {
        i = a;
        a = b;
        b = i;
    }
    if(a > c) {
        i = a;
        a = c;
        c = i;
    }
    if(b > c) {
        i = b;
        b = c;
        c = i;
    }

    cout << "\nSerazene hodnoty: " << a << " -> " << b << " -> " << c << "\n";
    finishProgram();
    return 0;
}

void validateInput() {
    if(cin.fail()) {
        cout << "Program funguje jen pro cela cisla!\n";
        cin.clear();
        finishProgram();
    }
}

void finishProgram() {
    cout << "Odeslete jakoukoliv hodnotu pro ukonceni programu.\n";

    cin.clear();

    short i;
    cin >> i;

    exit(0);
}
