#include <iostream>
#include <cstring>
using namespace std;

int cnt;

int recursion(const char* s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		cnt = 0;

		cout << recursion(s.c_str(), 0, s.length() - 1) << " " << cnt << "\n";
	}
	
}