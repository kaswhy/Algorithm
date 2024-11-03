#include <bits/stdc++.h>
using namespace std;

int cnt[1000002];
int par[1000002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    fill(cnt, cnt+n+1, INT_MAX);

    cnt[1] = 0;
    for(int i = 2; i<=n; i++){
        cnt[i] = cnt[i-1] + 1;
        par[i] = i-1;

        if(i%2 == 0 && cnt[i] > cnt[i/2] + 1){
            cnt[i] = cnt[i/2]+1;
            par[i] = i/2;
        }
        if(i%3 == 0 && cnt[i]> cnt[i/3] +1) {
            cnt[i] = cnt[i/3] + 1;
            par[i] = i/3;
        }
    }

    cout << cnt[n] << "\n";
    int now = n;
    while(true) {
        cout << now << " ";
        if(now == 1) break;
        now = par[now];
    }
}