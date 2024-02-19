#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	bool* primeArray = new bool[n + 1];

	memset(primeArray, 1, n + 1);

	primeArray[0] = 0;
	primeArray[1] = 0;

	for (int i = 2; i * i <= n; i++) {
		if (primeArray[i]) {
			for (int j = i * i; j <= n; j += i) {
				primeArray[j] = 0;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (primeArray[i]) {
			cout << i << "\n";
		}
	}
}