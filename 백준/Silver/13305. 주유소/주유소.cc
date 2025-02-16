#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int n;
    cin >> n;

    vector<unsigned long long int> dist(n-1, 0);
    for(unsigned long long int i = 0; i<n-1; i++){
        cin >> dist[i];
    }

    unsigned long long int min = 1000000001;
    unsigned long long int cnt = 0;
    for(unsigned long long int i = 0; i<n; i++){
        unsigned long long int x;
        cin >> x;

        if(i == n-1) break;

        if(min > x) min = x;
        cnt += min * dist[i];
    }

    cout << cnt;
}