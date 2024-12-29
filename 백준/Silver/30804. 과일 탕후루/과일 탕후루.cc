#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> tanghuru(n);
    vector<int> fruits(10,0);

    for(int i = 0; i<n; i++){
        cin >> tanghuru[i];
    }

    int l = 0, r = 0, ans = 0;
    while(r<n) {
        fruits[tanghuru[r]]++;
        r++;

        while(10 - count(fruits.begin(), fruits.end(), 0) > 2) {
            fruits[tanghuru[l]]--;
            l++;
        }
        ans = max(ans, r-l);
    }
    cout << ans;
}