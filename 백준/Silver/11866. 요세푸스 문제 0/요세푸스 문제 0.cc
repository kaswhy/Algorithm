#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> que;
	for (int i = 0; i < n; i++) {
		que.push_back(i + 1);
	}

	int idx = 0;
	while (!que.empty()) {
		if (que.size() == n) {
			cout << "<";
		}
		
		idx += k - 1;
		idx %= que.size();

		cout << que[idx];
		que.erase(que.begin() + idx);
		

		if (que.empty()) {
			cout << ">";
		}

		else {
			cout << ", ";
		}
	}
}