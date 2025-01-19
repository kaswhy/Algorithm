#include <bits/stdc++.h>
using namespace std;

int v[1002][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < 10; i++){
        v[1][i] = 1;
    }

    for(int i = 2; i < 1002; i++) {
        for(int j = 0; j < 10; j++){
            for(int k = 0; k<=j; k++){
                v[i][j] += v[i-1][k];
                v[i][j] %= 10007;
            }
        }
    }

    cout << v[n+1][9];
}