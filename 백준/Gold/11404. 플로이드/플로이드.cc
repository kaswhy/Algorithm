#include <bits/stdc++.h>
using namespace std;

int n, m;
int cost[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++) {
        fill(cost[i], cost[i] + n + 1, 10000001);
        cost[i][i] = 0;
    }

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for(int k = 1; k<= n; k++){
        for(int i = 1; i<= n; i++) {
            for(int j = 1; j<= n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }


    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<= n; j++) {
            if(cost[i][j]==10000001) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }

}