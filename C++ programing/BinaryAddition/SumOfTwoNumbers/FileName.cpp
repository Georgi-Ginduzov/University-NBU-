#include <iostream>

int main() {
    const int count = 8;

    int a[count];
    int b[count];
    int c[count]; // one extra digit for potential carry

    std::cout << "Enter the first number: ";
    for (int i = 0; i < count; i++)
    {
        std::cin >> a[i];
    }
    std::cout << "Enter the second number: ";
    for (int i = 0; i < count; i++)
    {
        std::cin >> b[i];
    }

    int carry = 0, sum = 0;

    for (int k = count - 2; k >= 0; k--)
    {
        sum = a[k] + b[k] + carry;
        c[k + 1] = sum % 2;
        carry = sum / 2;
    }
    
    if (sum == 3)
    {
        for (int i = 0; i < count - 2; i++)
        {
            c[i] = 0;
        }
        c[count - 1] = 1;
    }

    std::cout << "The sum is: ";
    for (int i = 0; i < count - 1; i++)
    {
        std::cout << c[i];
    }

    return 0;
}
