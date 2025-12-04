#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string vps;

	cin >> t;
	while (t--) {
		cin >> vps;
		stack<int> v_stack;

		for (int i = 0; i < vps.length(); i++) {
			if (vps[i] == '(') {
				v_stack.push(1);
			}
			else if (vps[i] == ')') {
				if (v_stack.empty()) {
					cout << "NO" << "\n";
					break;
				}
				v_stack.pop();
			}

			if (!v_stack.empty() && i == vps.length() - 1) {
				cout << "NO" << "\n";
			}

			else if (v_stack.empty() && i == vps.length() - 1) {
				cout << "YES" << "\n";
			}
		}
	}
}