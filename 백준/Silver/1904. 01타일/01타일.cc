#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<unsigned long long> v(n+1);
    v[1] = 1;
    v[2] = 2;

    for(int i = 3; i<=n; i++){
        v[i] = (v[i-1] % 15746 + v[i-2] % 15746) % 15746;
    }

    cout << v[n];
}