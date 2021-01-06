#include <iostream>
#include <ctime>
#include <algorithm>

void finishProcess();

int main() {
    std::cout << "Number Generator: Enter number count to generate:" << std::endl;

    int length;
    std::cin >> length;
    if(std::cin.fail()) {
        std::cout << "Invalid number specified!" << std::endl;

        finishProcess();
        return 0;
    }

    srand(time(nullptr) + 1);

    int array[length];
    for(int i = 0; i < length; i++) {
        array[i] = rand() % 10;
    }

    // A) Print array
    std::cout << "A) Printed array: " << std::endl;
    std::cout << "array(" << length << ") {" << std::endl;
    for(int i = 0; i < length; i++) {
        std::cout << "  " << i << " => " << array[i] << (i == length - 1 ? "" : ",") << std::endl;
    }
    std::cout << "}" << std::endl << std::endl;

    // B) Print reversed array
    std::cout << "B) Printed reversed array: " << std::endl;
    std::cout << "array(" << length << ") {" << std::endl;
    for(int i = length - 1; i >= 0; i--) {
        std::cout << "  " << ((length - i) - 1) << " => " << array[i] << (i == 0 ? "" : ",") << std::endl;
    }
    std::cout << "}" << std::endl << std::endl;

    // C) Min/Max
    std::cout << "C) Calculate minimum/maximum: " << std::endl;
    int min = -1, max = -1;
    for(int i = 0; i < length; i++) {
        if(min == -1) {
            min = array[i];
            max = array[i];
            continue;
        }

        min = std::min(min, array[i]);
        max = std::max(max, array[i]);
    }
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Maximum: " << max << std::endl << std::endl;

    // D) Average
    std::cout << "D) Calculate average:" << std::endl;
    int all = 0;
    for(int i = 0; i < length; i++) {
        all += array[i];
    }
    std::cout << "Average: " << (((double) all) / ((double)length)) << std::endl << std::endl;

    // E) Even/odd number count
    std::cout << "E) Calculate even and odd number count:" << std::endl;
    int even = 0, odd = 0;
    for(int i = 0; i < length; i++) {
        if(array[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    std::cout << "Even number count: " << even << std::endl;
    std::cout << "Odd number count: " << odd << std::endl << std::endl;

    // F) Sort it and print again
    std::cout << "F) Print numbers in ascending order and in descending order:" << std::endl;
    std::sort(array, array + length);

    std::cout << "Ascending order:" << std::endl;
    std::cout << "array(" << length << ") {" << std::endl;
    for(int i = 0; i < length; i++) {
        std::cout << "  " << i << " => " << array[i] << (i == length - 1 ? "" : ",") << std::endl;
    }
    std::cout << "}" << std::endl << std::endl;

    std::cout << "Descending order: " << std::endl;
    std::cout << "array(" << length << ") {" << std::endl;
    for(int i = length - 1; i >= 0; i--) {
        std::cout << "  " << ((length - i) - 1) << " => " << array[i] << (i == 0 ? "" : ",") << std::endl;
    }
    std::cout << "}" << std::endl << std::endl;

    std::cout << "Done! Press [Enter] to exit." << std::endl;
    return 0;
    
    finishProcess();
}

void finishProcess() {
    std::cin.clear();
    std::cin.get();
    std::cin.get();
}
