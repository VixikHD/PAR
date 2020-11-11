#include <iostream>
#include "vector"
#include "cstdlib"

void checkInputValidity();

using namespace std;

int main() {
    cout << "Zadejte rok:\n";

    vector<int> all;
    int current;

    do {
        cin >> current;
        checkInputValidity();

        if(current < 1582) {
            cout << "Tento rok neni v gregorianskem kalendari, zkus jiny rok\n";

            cin >> current;
            continue;
        }

        cout << "Roky:\n";

        all.push_back(current);

        int leaps = 0;
        for(int i = 0; i < all.size(); i++) {
            int currentYear = all.at(i);

            bool isLeapYear = currentYear % 4 == 0 && (current % 100 != 0 || currentYear % 400 == 0);
            if(isLeapYear) {
                leaps++;
            }

            cout << i + 1 << ": " << currentYear << " - Prestupny: " << (isLeapYear ? "ANO" : "NE") << "\n";
        }

        int normals = (int)all.size() - leaps;
        int diff = leaps - normals;

        cout << "\nStatistiky:\n";
        cout << "  " << leaps << " prestupnych roku mezi zadanymi\n";
        cout << "  " << normals << " neprestupnych roku mezi zadanymi\n";
        cout << "  " << "Zadano o " << abs(diff) << " prestupnych roku " << (diff < 0 ? "mene" : "vice") << " nez roku neprestupnych\n\n";

        cout << "Zadejte dalsi rok nebo 0 pro ukonceni.\n\n";
    }
    while (current != 0);

    cout << "Ukoncuji program...";
    cin.clear();
    cin.get();
    return 0;
}

void checkInputValidity() {
    if(cin.fail()) {
        cout << "Vlozena invalidni hodnota\n";
        exit(0);
    }
}
