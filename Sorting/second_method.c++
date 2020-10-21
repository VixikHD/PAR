#include <iostream>
#include "cstdlib"

void validateInput();
void finishProgram();

void displaySortedValues(int i, int j, int k);

using namespace std;

int main() {
    cout << "Razeni cisel bez pomocne bunky:\n\n";
    int a,b,c;

    cout << "Zadejte A:\n";
    cin >> a;
    validateInput();

    cout << "Zadejte B:\n";
    cin >> b;
    validateInput();

    cout << "Zadejte C:\n";
    cin >> c;
    validateInput();

    if (a > b) {
        if(a > c) {
            if(b > c) {
                displaySortedValues(c, b, a);
            }
            displaySortedValues(b, c, a);
        }
        displaySortedValues(b, a, c);
    }
    if(b > c) {
        if(a > c) {
            displaySortedValues(c, a, b);
        }
        displaySortedValues(a, c, b);
    }
    displaySortedValues(a, b, c);

    return 0;
}

void displaySortedValues(int i, int j, int k) {
    cout << "\nSerazene hodnoty: " << i << " -> " << j << " -> " << k << "\n";
    finishProgram();
}

void validateInput() {
    if(cin.fail()) {
        cout << "Program funguje jen pro cela cisla!\n";
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
