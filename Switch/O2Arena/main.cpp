#include <iostream>

void waitForNextResponse();

using namespace std;

int main() {
    cout << "Enter the part (1-5) of o2 arena, for which you want to display value:\n";

    short sector;
    cin >> sector;

    if(cin.fail()) {
        cout << "\nUnknown sector, use number next time.\n";

        waitForNextResponse();
        return 0;
    }

    switch (sector) {
        case 1:
            cout << "Ticket price: 500kc\n";
            waitForNextResponse();
            return 0;
        case 2:
            cout << "Ticket price: 750kc\n";
            waitForNextResponse();
            return 0;
        case 3:
            cout << "Ticket price: 1000kc\n";
            waitForNextResponse();
            return 0;
        case 4:
            cout << "Ticket price: 1500kc\n";
            waitForNextResponse();
            return 0;
        case 5:
            cout << "Ticket price: 2000kc\n";
            waitForNextResponse();
            return 0;
        default:
            cout << "Unknown sector\n";
            waitForNextResponse();
            return 0;
    }
}

void waitForNextResponse() {
    cin.clear();
    cin.get();
}
