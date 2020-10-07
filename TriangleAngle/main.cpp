#include <iostream>
#include "cmath"
#include "string"

using namespace std;

const double PI = 4 * atan(1);

void validateInput();
void endWithError(const string& error);
string rad2Deg(double radians);
void finishProgram();

int main() {
    cout << "Dopocitavani uhlu trojuhelniku:\n\n";
    double a,b,c;

    cout << "Zadejte delku strany A:\n";
    cin >> a;
    validateInput();

    cout << "Zadejte delku strany B:\n";
    cin >> b;
    validateInput();

    cout << "Zadejte delku strany C:\n";
    cin >> c;
    validateInput();

    if(a+b <= c || b+c <= a || c+a <= b || a <= 0 || b <= 0 || c <= 0) {
        endWithError("Ze zadanych stran nelze vytvorit trojuhelnik!");
    }

    cout << "Pocitam...\n\n";

    double alfaRad = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
    double betaRad = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
    double gamaRad = PI - (betaRad + alfaRad);

    cout << "Alfa = " << rad2Deg(alfaRad) << "\n";
    cout << "Beta = " << rad2Deg(betaRad) << "\n";
    cout << "Gama = " << rad2Deg(gamaRad) << "\n";
    return 0;
}

string rad2Deg(double radians) {
    int degrees,minutes;
    double seconds;

    degrees = (int) ((180 * radians) / PI);
    minutes = (int) ((((180 * radians) / PI) - degrees) * 60);
    seconds = (((((180 * radians) / PI) - degrees) * 60) - minutes) * 60;

    return to_string(degrees) + " Stupnu " + to_string(minutes) + " Minut a " + to_string(seconds) + " Sekund";
}

void endWithError(const string& error) {
    cout << error << "\nUkoncuji program...";
    finishProgram();
}

void finishProgram() {
    cin.clear();
    cin.get();

    exit(0);
}

void validateInput() {
    if(cin.fail()) {
        cout << "Zadana spatna hodnota!\nUkoncuji program...";
        finishProgram();
    }
}
