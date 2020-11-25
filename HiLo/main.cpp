#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int minGenerated = 0;
const int maxGenerated = 1024;

int generatedNumber;
int attempts = 1;
bool numberFound = false;

void init_rand();
int generate_random_number();

int main() {
    init_rand();

    generatedNumber = generate_random_number();
    std::cout << "Try finding number between " << minGenerated << " and " << maxGenerated << std::endl;

    int lastAttempt;
    do {
        std::cin >> lastAttempt;
        if(std::cin.fail()) {
            std::cout << "Specify number!" << std::endl;
            continue;
        }

        lastAttempt = std::max(minGenerated, std::min(maxGenerated, lastAttempt));
        if(lastAttempt == generatedNumber) {
            numberFound = true;
            continue;
        }

        std::cout << attempts << ". attempt: Target number is " << (generatedNumber < lastAttempt ? "lower" : "higher") << " than " << lastAttempt << "" << std::endl;
        attempts++;
    }
    while (!numberFound);

    std::cout << "-----------------------------------------\n"
                 "    *             *              *\n"
                 "       *     CONGRATULATION   *        *\n"
                 "  *     You have found the number!   *\n"
                 "      *     Searched number: " << generatedNumber << "\n"
                 "    *     *   Attempts: " << attempts << "     *\n"
                 " *             *          *          *\n"
                 "-----------------------------------------";

    std::cin.clear();
    std::cin.get();
    std::cin.get();
}

void init_rand() {
    srand(time(0) + 1);
}

int generate_random_number() {
    return minGenerated + (rand() % (maxGenerated - minGenerated + 1));
}
