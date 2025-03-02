#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // n은 표 크기, m은 질의
    cin >> n >> m;

    vector<vector<int>> square(n+1, vector<int>(n+1, 0));
    vector<vector<int>> sums(n+1, vector<int>(n+1, 0)); // 부분합

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) {
            cin >> square[i][j];
            sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + square[i][j];
        }
    }

    for(int i = 0; i<m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sums[x2][y2] - sums[x2][y1-1] - sums[x1-1][y2] + sums[x1-1][y1-1] << "\n";
    }
}
