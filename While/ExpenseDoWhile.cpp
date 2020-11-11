#include <iostream>
#include "vector"

using namespace std;

void checkForInvalidInput();
void printExpense(vector<int> &all);

int main() {
    cout << "Zadejte vydaje:\n";

    vector<int> all; // chtel jsem se naucit neco noveho, proto pouzivam vektory
    int current;
    do {
        cin >> current;
        checkForInvalidInput();

        cout << "Vydaje:\n";

        all.push_back(current);
        printExpense(all);

        cout << "Zadejte dalsi vydaje, nulu pro ukonceni programu:\n";
    }
    while (current != 0);

    printExpense(all);
    cout << "Uknocuji program!";

    cin.clear();
    cin.get();
}

void printExpense(vector<int> &all) {
    int plus = 0;
    int minus = 0;
    for(int i = 0; i < all.size(); i++) {
        if(all.at(i) < 0) {
            minus += -all.at(i);
        } else {
            plus += all.at(i);
        }
        cout << i << ": " << all.at(i) << "\n";
    }

    int final = plus - minus;

    cout << "\nVysledek:\n";
    cout << "  [+] " << plus << "\n";
    cout << "  [-] -" << minus << "\n";
    cout << "  -> " << (final == 0 ? ("Neutralni vysledek") : (final > 0 ? "Jsme v plusu" : "Jsme v minusu")) << " (" << final << ")\n\n";
}

void checkForInvalidInput() {
    if(cin.fail()) {
        cout << "Vlozena invalidni hodnota\n";
        exit(0);
    }
}
