#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <string>

using namespace std;

void clearScreen() {
    system("cls");
}

void printSinus() {
    //clearScreen();
    double pi = 4 * atan(1);
    int values[100];
    for(int j = 0; j < 100; j++) {
        double v = (sin(j * pi / 16) * 4) + 10;
        values[j] = v;
    }

    for(int y = 0; y < 20; y++) {
        for(int x = 0; x < 100; x++) {
            if(x == 0) {
                if(y == 0) {
                    cout << "/";
                }
                else if(y == 19) {
                    cout << "\\";
                }
                else {
                    cout << "|";
                }
            }
            else if(y == 10) {
                cout << "-";
            }
            else {
                if(values[x] == y) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }

    int i;
    cin >> i;
}

void convertRadToDeg() {
    cout << "Vlozte hodnotu v radianech\n";

    double rad;
    cin >> rad;
    if(cin.fail()) {
        cout << "Pouzij spravnou hodnotu\n";
        int i;
        cin >> i;
        return;
    }

    double pi = atan(1) * 4 ;

    double degrees = 180 * rad / pi;
    int fullDegrees = degrees;
    double left = 60 * (degrees - fullDegrees);

    int fullMinutes = left;
    double seconds = 60 * (left - fullMinutes);

    cout << "" << rad << "RAD = " << fullDegrees << " Stupnu, "<< fullMinutes <<" Minut a " << seconds << " Vterin" << endl;

    int i;
    cin >> i;
}

void convertDegToRad() {
    cout << "Vlozte hodnotu v deg\n";

    int deg;
    cin >> deg;
    if(cin.fail()) {
        cout << "Pouzij spravnou hodnotu\n";
        int i;
        cin >> i;
        return;
    }

    double pi = atan(1) * 4 ;
    double rad = deg / 180;
    double radWithPI = rad * pi;

    cout << "Hodnota v radianech = " << radWithPI << " (" << rad << "*pi)";
    int i;
    cin >> i;
    return;
}

int main() {
    cout << "Zadejte typ funkce k zobrazeni\n";
    cout << "0: sin(x)\n";
    cout << "1: cos(x)\n";
    cout << "2: preved rad na deg\n";
    cout << "3: preved deg na rad\n";

    int option;
    cin >> option;

    if(cin.fail()) {
        option = -1;
    }

    switch(option) {
        case 0:
            printSinus();
            break;
        case 1:
            break;
        case 2:
            convertRadToDeg();
            break;
        case 3:
            convertDegToRad();
            break;
        default:
            cout << "Invalid function";
            break;
    }
}
