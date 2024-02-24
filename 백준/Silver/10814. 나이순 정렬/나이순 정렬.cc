#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;

	multimap<int, string> people;

	for (int i = 0; i < t; i++) {
		int age;
		string name;

		cin >> age >> name;

		people.insert({ age, name });
	}

	for (auto it : people) {
		cout << it.first << " " << it.second << "\n";
	}
}