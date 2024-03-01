#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long int> v, answer;
	for (int i = 0; i < n; i++) {
		long long int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		long long int x;
		cin >> x;
		answer.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		long long int goal = answer[i];

		int min = 0;
		int mid = v.size() / 2;
		int max = v.size() - 1;
		int chk = 0;

		while (min != mid && mid!=max ) {
			if (goal == v[mid] || goal == v[min] || goal == v[max]) {
				chk = 1;
				break;
			}
			else if (goal > v[mid]) {
				min = mid;
				mid = (min + max) / 2;
			}
			else if (goal < v[mid]) {
				max = mid;
				mid = (min + max) / 2;
			}
		}

		if (chk == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}