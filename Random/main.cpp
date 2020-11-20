#include <iostream>
#include <ctime>
#include <cstdlib>
#include "vector"
//#include <random>

using namespace std;

int minValue = 5;
int maxValue = 15;

int valuesCount = 20;

void read_custom_values();
void validateInput();

int main() {
    srand(time(0) + 1); // Nevim proc, ale program, ve kterem to delam, pise ze pouziti pouze funkce na cas by se nemelo pouzivat (https://i.ibb.co/wh0DPb5/obrazek.png), bylo to zvyraznene, tak jsem to takhle (s +1) opravil

    read_custom_values(); // po 'odkomentovani' bude program pozadovat vlozeni hodnot po startu

    int fixedMin = max(0, minValue);
    int fixedMax = max(0, maxValue);

//    random_device device; // po 'odkomentovani' se bude pouzivat knihovna, ktera generuje lepe (vice nahodne)
//    mt19937 generator(device());
//    uniform_int_distribution<int> distribution(fixedMin, fixedMax);

    vector<int> preGenerated;
    for(int i = 0; i < valuesCount; i++) {
//        int randomNumber = distribution(generator);
        int randomNumber = fixedMin + (rand() % (fixedMax - fixedMin + 1)); // Funkce rand() je take zvyraznena, mela by se nahradit knihovnou Random z c++ 11 (https://i.ibb.co/Msn13gL/obrazek.png)

        preGenerated.push_back(randomNumber);
    }


    cout << "\nGenerated numbers (min=" << fixedMin << ";max=" << fixedMax << ";numbersCount=" << valuesCount << "):\n\n";
    int current = 1;
    for(int i = fixedMin; i <= fixedMax; i++) {
        int valCount = 0;
        for(int j = 0; j < preGenerated.size(); j++) {
            if(preGenerated.at(j) == i) {
                valCount++;
            }
        }

        int percentage = (int) ((100 * valCount) / valuesCount);
        cout << current << ": Number=" << i << " => Generated " << valCount << " times (=" << percentage << "%)\n";

        current++;
    }

    cin.clear();
    cin.get();

    return 0;
}

void read_custom_values() {
    cout << "Insert number A (minimum):";
    cin >> minValue;
    validateInput();

    cout << "Insert number B (maximum):";
    cin >> maxValue;
    validateInput();

    cout << "Insert how many values should program generate:";
    cin >> valuesCount;
    validateInput();

    if(minValue > maxValue) {
        cout << "Minimum value must have been higher than the maximum one.\n";

        cin.clear();
        cin.get();

        exit(0);
    }

    cout << "Generating...\n";
}

void validateInput() {
    if(cin.fail()) {
        cout << "Invalid value\n";

        cin.clear();
        cin.get();
        exit(0);
    }
}
