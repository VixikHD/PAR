#include <iostream>
#include "cstdlib"

void waitForNextResponse();
void validateInput();

using namespace std;

int main() {
    int firstNum, secondNum;
    short operation;
    string operationSymbol;
    double result;

    cout << "Simple calc:\n\n";
    cout << "Enter first number:\n";

    cin >> firstNum;
    validateInput();

    cout << "\n-> " << firstNum << " ? y = z\n\n";
    cout << "Enter second number:\n";

    cin >> secondNum;
    validateInput();

    cout << "\n-> " << firstNum << " ? " << secondNum << " = z\n\n";
    cout << "Select operation: \n";
    cout << " 1 -> [+]\n 2 -> [-]\n 3 -> [*]\n 4 -> [/]\n\n";

    cin >> operation;
    validateInput();

    cout << "Calculating...\n\n";

    switch (operation) {
        case 1:
            result = firstNum + secondNum;
            operationSymbol = "+";
            break;
        case 2:
            result = firstNum - secondNum;
            operationSymbol = "-";
            break;
        case 3:
            result = firstNum * secondNum;
            operationSymbol = "*";
            break;
        case 4:
            result = (double)firstNum / secondNum;
            operationSymbol = "/";
            break;
        default:
            cout << "Unknown operation specified\n";
            waitForNextResponse();
            return 0;
    }

    cout << "-> " << firstNum << " " << operationSymbol << " " << secondNum << " = " << result << "\n";
    waitForNextResponse();
    return 0;
}

void validateInput() {
    if(cin.fail()) {
        cout << "Specify real number.\n";
        waitForNextResponse();
        exit(0);
    }
}

void waitForNextResponse() {
    cin.clear();
    cin.get();
}
