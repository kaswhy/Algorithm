#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	int v[10001] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x] += 1;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < v[i]; j++) {
			cout << i << "\n";
		}
	}
}