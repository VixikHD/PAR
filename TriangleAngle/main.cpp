#include <iostream>
#include <sstream>
#include "cmath"
#include "string"
#include "cstdlib"

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

    finishProgram();
}

string rad2Deg(double radians) {
    int degrees,minutes;
    double seconds;

    degrees = (int) ((180 * radians) / PI);
    minutes = (int) ((((180 * radians) / PI) - degrees) * 60);
    seconds = (((((180 * radians) / PI) - degrees) * 60) - minutes) * 60;

    stringstream stringStream; // omlovuam se, pouzival jsem novejsi verzi c++
    stringStream << degrees << " Stupnu " << minutes << " Minut a " << seconds << " Sekund";

    return stringStream.str();
}

void endWithError(const string& error) {
    cout << error << "\nUkoncuji program...";
    finishProgram();
}

void finishProgram() {
    short i;
    cin >> i;

    exit(0);
}

void validateInput() {
    if(cin.fail()) {
        endWithError("Zadana spatna hodnota!");
    }
}
