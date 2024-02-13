#include <iostream>
using namespace std;

int main() {
	/*
	1       (1)  - 1
	2  ~ 7  (6)  - 2
	8  ~ 19 (12) - 3
	20 ~ 37 (18) - 4
	38 ~ 61 (24) - 5
	
	0 ~ 5 - 0             1
	6 ~ 17 - 1, 2         2
	18 ~ 35 - 3, 4, 5     3
	36 ~ 59 - 6, 7, 8, 9  4
	
	*/
	long long int n, x = 1, inc = 1;
	cin >> n;
	
	while (1) {
		if (n <= x) {
			cout << inc;
			break;
		}
		inc++;
		x += 6 * (inc - 1);
	}
}