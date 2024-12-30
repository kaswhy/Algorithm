#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> kevin(n+1, vector<int>(n+1, 9999999));
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;

        kevin[x][y] = 1;
        kevin[y][x] = 1;
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<= n; j++){
            for(int k = 1; k<= n; k++){
                if(kevin[j][k] > kevin[j][i] + kevin[i][k]){
                    kevin[j][k] = kevin[j][i] + kevin[i][k];
                }
            }
        }
    }

    int minimum = 99999999, idx = -1;
    for(int i = 1; i<= n; i++) {
        int now = 0;
        for(int j = 1; j<=n; j++){
            now += kevin[i][j];
        }
        if(minimum > now) {
            minimum = now;
            idx = i;
        }
    }

    cout << idx;
}
