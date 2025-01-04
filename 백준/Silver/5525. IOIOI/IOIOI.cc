#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s = "";
    for(int i = 0; i<n; i++) {
        s += "IO";
    }
    s += "I";

    string ans;
    cin >> ans;

    int cnt = 0;

    for(int i = 0; i<m; i++){
        if(ans.substr(i,2*n+1) == s) {
            cnt++;
        }
    }

    cout << cnt;
}