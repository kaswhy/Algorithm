#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<long int> v(n+1);
    v[1] = 1, v[2] = 1;
    for(long int i = 3; i<=n; i++){
        v[i] = v[i-1] + v[i-2];
    }

    cout << v[n];
}