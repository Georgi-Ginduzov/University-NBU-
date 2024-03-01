#include <iostream>
#include <cstdlib>

    using std::cout;
    using std::cin;

        int main() {

            int n;

            cin >> n;

            int* a1 = new int[n];
            int* b2 = new int[n];
            int* sum = new int[n];

            for (int i = 0; i < n; i++)
            {
                cin >> a1[i];
            }
            for (int i = 0; i < n; i++)
            {
                cin >> b2[i];
            }

            if (a1 < b2)
            {
                std::swap(a1, b2);
            }

            int carry = 0, c1;

            for (int k = 0; k < 2; k++)
            {
                sum[k] = a1[k] + b2[k] + carry;
                c1 = sum[k] % 10;
                div_t div_result = div(carry, 10); //carry = .. div 10
                carry = div_result.quot;
            }

            c1 = carry;

            cout << sum;

        }