#include <iostream>
#include <vector>

using namespace std;

int sum(const int N) {
	/*int arr[n + 1];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 0; i <= n; i++)
	{
		int p = arr[i / 4] + arr[i / 3] + arr[i / 2];
		arr[i] = i > p ? i : p;
	}
	*/
	return N;

}

int main() {
	const int N = 2;
	int arr[N + 1];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 0; i <= N; i++)
	{
		int p = arr[i / 4] + arr[i / 3] + arr[i / 2];
		arr[i] = i > p ? i : p;
	}

	cout << "Result: " << arr[N] << endl;

	cout << 2 / 3;
}