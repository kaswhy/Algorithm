#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string ans;
    cin >> ans;

    int cnt = 0;

    for(int i = 0; i < m; i++) {
        if(ans[i] == 'O'){
            continue;
        }
        int len = 0;
        while(ans[i+1] == 'O' && ans[i+2] == 'I') {
            len++;
            if(len == n){
                len--;
                cnt++;
            }
            i += 2;
        }
    }

    cout << cnt;
}