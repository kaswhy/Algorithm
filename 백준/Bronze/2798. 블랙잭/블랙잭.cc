#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int max = 0, tmp = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				tmp = v[i] + v[j] + v[k];
				if (tmp > m) {
					continue;
				}
				if (tmp > max && tmp <= m) {
					max = tmp;
				}
			}
		}
	}

	cout << max;

}