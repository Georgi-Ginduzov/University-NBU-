#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    double x = 3;
    double tolerance = 0.0001;
    double sinX = 0.0;
    double term;
    int n = 0;

    do {
        term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sinX += term;
        n++;
    } while (abs(term) >= tolerance);

    cout << "sin(x): " << sinX << endl;

    return 0;
}
