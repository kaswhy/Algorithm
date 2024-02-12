#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> st;

	while (n--) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}

		else if (s == "pop") {
			if (st.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << st.top() << "\n";
			st.pop();
		}

		else if (s == "size") {
			cout << st.size() << "\n";
		}

		else if (s == "empty") {
			if (st.empty()) {
				cout << 1 << "\n";
				continue;
			}
			cout << 0 << "\n";
		}


		else if (s == "top") {
			if (st.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << st.top() << "\n";
		}
	}
}