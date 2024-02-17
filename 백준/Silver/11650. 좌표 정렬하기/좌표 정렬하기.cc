#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(200001);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x + 100000].push_back(y);
	}

	for (int i = 0; i < 200001; i++) {
		if (!v[i].empty()) {
			sort(v[i].begin(), v[i].end());
			for (int j = 0; j < v[i].size(); j++) {
				cout << i - 100000 << " " << v[i][j] << "\n";
			}
		}
	}

}