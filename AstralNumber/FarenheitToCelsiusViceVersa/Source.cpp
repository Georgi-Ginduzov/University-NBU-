#include <iostream>
#include <cctype>
#include <string>

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

		int celsiusToFahrenheit(float celsius, float fahrenheit) {
			return celsius * 1.8 + 32;
		}

		int fahrenheitToCelsius(float fahrenheit, double celsius) {
			return (fahrenheit - 32) * 0.55556;
		}

		int main() {

			std::string temperature;

			cout << "Enter temperature: ";
			cin >> temperature;

			int lastElement = temperature.size() - 1;

			int celsius = 0, fahrenheit = 0;

			if (tolower(temperature[lastElement]) == 'c')
			{
				cout << "The temperature in celsius is: " << temperature << endl;

				temperature = temperature.erase(lastElement);

				celsius = std::stoi(temperature);

				fahrenheit = celsiusToFahrenheit(celsius, fahrenheit);

				cout << "The temperature in fehrenheit is: " << fahrenheit;

			}
			else if (tolower(temperature[lastElement]) == 'f')
			{
				cout << "The temperature in farenheit is: " << temperature << endl;

				temperature = temperature.erase(lastElement);

				fahrenheit = std::stoi(temperature);

				cout << fahrenheit << endl;

				celsius = fahrenheitToCelsius(fahrenheit, celsius);

				cout << "The temperature in celcius is: " << celsius;

			}

			return 0;
		}