#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else return a.length() < b.length();
}

int main() {
	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	cout << v[0] << "\n";
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i - 1]) {
			cout << v[i] << "\n";
		}
	}
}