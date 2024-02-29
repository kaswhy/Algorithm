#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l;
	cin >> l;

	string s;
	cin >> s;

	long long int x = 0;
	for (int i = 0; i < l; i++) {
		x += (int(s[i] - 96)) * pow(31, i);
	}

	cout << x % 1234567891;
}