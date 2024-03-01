#include <iostream>
#include <cmath>

int main() {
    int counterIterations = 10000;
    double pi = 0.0;
    for (int i = 0; i < counterIterations; i++) {
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }
    double piCounter = pi * 4.0;
    std::cout << "Calculated pi value: " << piCounter << std::endl;
    return 0;
}
