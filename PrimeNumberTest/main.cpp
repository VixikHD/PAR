#include <iostream>
#include <ctime>

void finish_process();
bool is_prime(int number);

int main()
{
    std::cout << "Enter maximum limit" << std::endl;
    int i;
    std::cin >> i;

    if(std::cin.fail()) {
        std::cout << "This is not valid number";
        finish_process();
        return 0;
    }

    double start_time = time(0);

    int found = 0;
    for(int j = 2; j <= i; j++) {
        if(is_prime(j)) {
            std::cout << "Found number " << j << std::endl;
            found++;
        }
    }

    std::cout << "Found " << found << " numbers in " << (time(0) - start_time) << " seconds!" << std::endl;
    finish_process();
    return 0;
}

void finish_process() {
    std::cin.clear();
    std::cin.get();
    std::cin.get();
}

bool is_prime(int number) {
    for(int i = 2; i < number; i++) {
        if(number % i == 0) {
            return false;
        }
    }

    return true;
}
