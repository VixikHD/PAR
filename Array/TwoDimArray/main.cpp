#include <iostream>
#include <ctime>

void finishProgram();

int main() {
    std::cout << "Creating m x n array:" << std::endl << std::endl;

    std::cout << "Enter m value: " << std::endl;
    int m;
    std::cin >> m;
    if(std::cin.fail() || m <= 0) {
        std::cout << "Invalid m value" << std::endl;

        finishProgram();
        return 0;
    }

    std::cout << "Enter n value: " << std::endl;
    int n;
    std::cin >> n;
    if(std::cin.fail() || n <= 0) {
        std::cout << "Invalid n value" << std::endl;

        finishProgram();
        return 0;
    }

    srand(time(nullptr) + 1);

    // A) Generating and printing
    std::cout << std::endl << "Printed array:" << std::endl;

    int array[m][n];
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            array[x][y] = rand() % 10;

            std::cout << array[x][y] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    // M - row
    // N - column

    // B) Min / max for each column and row
    std::cout << "Calculating min/max in rows: " << std::endl;
    int min = -1, max = -1;
    for(int x = 0; x < m; x++) {
        std::cout << "Row " << x + 1 << ": ";
        for(int y = 0; y < n; y++) {
            std::cout << array[x][y] << " ";
            if(min == -1) {
                min = max = array[x][y];
                continue;
            }

            min = std::min(min, array[x][y]);
            max = std::max(max, array[x][y]);
        }

        std::cout << " Min=" << min << ";Max=" << max << std::endl;
        min = max = -1;
    }
    std::cout << std::endl;

    std::cout << "Calculating min/max in columns: " << std::endl;
    for(int y = 0; y < n; y++) {
        std::cout << "Column " << y + 1 << ": ";
        for(int x = 0; x < m; x++) {
            std::cout << array[x][y] << " ";
            if(min == -1) {
                min = max = array[x][y];
                continue;
            }

            min = std::min(min, array[x][y]);
            max = std::max(max, array[x][y]);
        }

        std::cout << " Min=" << min << ";Max=" << max << std::endl;
        min = max = -1;
    }
    std::cout << std::endl;

    // C) Generate main diagonal in n x n array
    std::cout << "Generate and print main diagonal in n x n array:" << std::endl;
    int anotherArray[n][n];
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            if(x == y) {
                anotherArray[x][y] = 1;
            } else {
                anotherArray[x][y] = 0;
            }
            std::cout << anotherArray[x][y] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // D) Generate diagonal in n x n array
    std::cout << "Generate and print diagonal in n x n array:" << std::endl;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            if(x == y || (n - x - 1 == y)) {
                anotherArray[x][y] = 1;
            } else {
                anotherArray[x][y] = 0;
            }
            std::cout << anotherArray[x][y] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // E) Reverse number in diagonals
    std::cout << "Generate m x n array with random numbers and reverse numbers in diagonals: " << std::endl << std::endl;

    std::cout << "Generated array: " << std::endl;
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            array[x][y] = rand() % 10;

            std::cout << array[x][y] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Array with reversed numbers in diagonals:" << std::endl;
    int i;
    for(int x = 0; x < m; x++) {
        for(int y = 0; y < n; y++) {
            if(x == y) {
                i = array[x][y];
                array[x][y] = array[x][n - y - 1];
                array[x][n - y - 1] = i;
            }

            std::cout << array[x][y] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;

    finishProgram();
    return 0;
}

void finishProgram() {
    std::cin.clear();
    std::cin.get();
    std::cin.get();
}
