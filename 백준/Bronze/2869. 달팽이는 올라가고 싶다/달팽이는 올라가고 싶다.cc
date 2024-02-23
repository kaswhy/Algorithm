#include <iostream>
using namespace std;

int main() {
	long long a, b, v;
	cin >> a >> b >> v;
	
	long long tmp = (v - a) % (a - b);

	if (tmp == 0) cout << (v - a) / (a - b) + 1;
	else cout << (v - a) / (a - b) + 2;
}