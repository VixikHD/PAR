#include <iostream>
#include <ctime>

const bool debug = false;

void first_method();
void second_method();

int main() {
    first_method();
    second_emthod();
    return 0;
}

void first_method() {
    std::cout << "[First Method] Calculating three digit numbers (from 100 to 999) with different digits..." << std::endl;

    double start_time = time(0);

    int found = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                if(i != j && j != k && i != k) {
                    if(debug) {
                        std::cout << "[First Method] Found number " << i << j << k << std::endl;
                    }

                    found++;
                }
            }
        }
    }

    std::cout << "[First Method] Found " << found << " numbers in " << (time(0) - start_time) << " seconds!" << std::endl;
}

void second_method() {
    std::cout << "[Second Method] Calculating three digit numbers (from 100 to 999) with different digits..." << std::endl;

    double start_time = time(0);

    int found = 0;
    for(int num = 100; num < 1000; num++) {
        int i = (int)(num / 100);
        int j = (int)((num - (i * 100)) / 10);
        int k = (int)(num - ((i * 100) + (j * 10)));

        if(i != j && j != k && i != k) {
            if(debug) {
                std::cout << "[Second Method] Found number " << num << std::endl;
            }

            found++;
        }
    }

    std::cout << "[Second Method] Found " << found << " numbers in " << (time(0) - start_time) << " seconds!" << std::endl;
}
