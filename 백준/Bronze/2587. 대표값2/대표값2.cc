#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    vector<int> v(5);
    for(int i = 0; i<5; i++) {
        cin >> v[i];
        cnt+= v[i];
    }
    sort(v.begin(), v.end());

    cout << cnt / 5 << "\n";
    cout << v[2];
}