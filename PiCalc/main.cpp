#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>

const int calculation_debug = 100000;
const int precision = 100;

int main() {
    std::cout << "Calculating PI... Press [Enter] to cancel calculation." << std::endl;

    double start_time = time(nullptr);

    long double pi = 0;
    int i;
    for(i = 0; !_kbhit(); i++) {
        pi += (4 * (pow(-1, i) / ((2 * i) + 1)));
        if(i % calculation_debug == 0) {
            std::cout << "Passed " << i << " calculations!" << std::endl;
        }
    }

    std::cout << "Calculated in " << (time(nullptr) - start_time) << " seconds (" << i << " calculations)." << std::endl;

    std::cout.precision(precision);
    std::cout << "PI=" << pi << std::endl;
    return 0;
}
