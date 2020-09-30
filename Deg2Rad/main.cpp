#include <iostream>
#include <math.h>

using namespace std;

const double PI = acos(-1);

void finishProgram() {
    cout << "Odesli libovolny prikaz pro ukonceni programu.\n";

    int i;
    cin >> i;
}

void submitFail() {
    cout << "Spatne vlozena hodnota.\n\n";

    finishProgram();
}

int main()
{
    cout << "Prevod STUPNU na RADIANY\n\n";
    cout << "Vlozte stupne:\n";

    int stupne,minuty;
    double vteriny;

    cin >> stupne;
    if(cin.fail()) {
        submitFail();

        return 0;
    }

    cout << "Vlozte minuty (nepovinne):\n";

    cin.clear(); // Pokud dáme enter pøedem, program se nezastaví
    cin.get();

    cin >> noskipws >> minuty;
    if(cin.fail()) {
        minuty = 0;
        cout << "Pouzita defaultni hodnota (=0)\n";
    }


    cout << "Vlozte vteriny (nepovinne):\n";

    cin.clear();
    cin.get();

    cin >> noskipws >> vteriny;
    if(cin.fail()) {
        vteriny = 0;
        cout << "Pouzita defaultni hodnota (=0)\n";
    }

    cout << "\nPocitam hodnotu pro " << stupne << " STUPNU; " << minuty << " MINUT; " << vteriny << " VTERIN...\n";

    double radianyBezPI = (stupne + (minuty / 60) + (vteriny / (60 * 60))) / 180;
    double radiany = radianyBezPI * PI;

    cout << "\n";
    cout << "Vypocitana hodnota: " << radiany << "\n";
    if(vteriny == 0 && minuty == 0) {
        cout << "Hodnota s PI: " << radianyBezPI << "*pi\n";
    }

    cout << "\n";
    finishProgram();
}
