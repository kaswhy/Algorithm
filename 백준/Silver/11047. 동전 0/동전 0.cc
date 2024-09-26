#include <bits/stdc++.h>
using namespace std;
int coin[10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    int idx = 0;
    for(int i = 0; i<n; i++){
        cin >> coin[i];
        if (k < coin[i]) {
            idx = i - 1;
            break;
        }
        idx=i;
    }

    int cnt = 0;
    while(idx >= 0){
        int tmp =  (k/coin[idx]);
        cnt += tmp;
        k = k % coin[idx];
        idx--;
    }
    cout << cnt;
}