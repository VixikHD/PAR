#include <iostream>
#include "algorithm"

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

    int i[3] = {a,b,c};
    sort(i, i + 3);

    displaySortedValues(i[0], i[1], i[2]);
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
