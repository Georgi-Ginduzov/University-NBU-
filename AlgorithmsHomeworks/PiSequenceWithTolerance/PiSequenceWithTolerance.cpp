#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    const double tolerance = 0.0001;
    double pi = 0.0;
    double prevPi = 0.0;
    int i = 0;
    do {
        prevPi = pi;
        pi += pow(-1, i) / (2.0 * i + 1.0);
        i++;
    } while (abs(pi - prevPi) >= tolerance);

    double pi_tolerance = pi * 4.0;

    cout << "Calculated π value: " << pi_tolerance << endl;

    return 0;
}