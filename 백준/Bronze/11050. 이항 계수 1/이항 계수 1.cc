#include <iostream>
using namespace std;

int factorial[11];

int main() {

	factorial[0] = 1;
	for (int i = 1; i <= 10; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	int n, k;
	cin >> n >> k;

	cout << factorial[n] / (factorial[k] * factorial[n - k]);

}