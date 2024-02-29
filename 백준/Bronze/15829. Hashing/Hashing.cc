#include <iostream>
using namespace std;

int main() {
	int l;
	cin >> l;

	string s;
	cin >> s;

	long long int x = 0, num = 1, p = 31;
	for (int i = 0; i < l; i++) {
		x += (int(s[i] - 96) * num) % 1234567891;;
		x %= 1234567891;;
		num = (num * p) % 1234567891;
	}

	cout << x;
}