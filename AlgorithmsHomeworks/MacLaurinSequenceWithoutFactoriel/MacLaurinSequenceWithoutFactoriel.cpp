#include <iostream>
#include <cmath>

using std::cout;

int main() {
    double x = 3;
    double tolerance = 0.0001;

    double sinX = 0.0;
    double term = x;
    int n = 1;

    while (abs(term) >= tolerance) {
        sinX += term;
        term *= -(x * x) / ((2 * n) * (2 * n + 1));
        n++;
    }
    cout << "sin(x) without factorial method: " << sinX << std::endl;

    return 0;
}