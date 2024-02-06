#include <iostream>
using namespace std;

long long int factorial(long long int n) {
	if (n <= 1) {
		return 1;
	}

	return n * factorial(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	long long int n;
	cin >> n;

	cout << factorial(n);

}