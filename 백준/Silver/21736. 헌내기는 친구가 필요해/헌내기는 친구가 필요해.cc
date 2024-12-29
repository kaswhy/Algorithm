#include <bits/stdc++.h>
using namespace std;

int n, m;
string campus[600];
bool visited[600][600];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    queue<pair<int, int>> que;
    int x_idx = 0, y_idx = 0;
    for(int i = 0; i<n; i++){
        cin >> campus[i];

        for(int j = 0; j<m; j++){
            if(campus[i][j] == 'I') {
                que.push({i, j});
            }
        }
    }

    int count = 0;
    while(!que.empty()){
        int now_x, now_y;
        tie(now_y, now_x) = que.front();
        que.pop();

        if(visited[now_y][now_x]) continue;
        if(campus[now_y][now_x] == 'P'){
            count++;
        }

        visited[now_y][now_x] = 1;



        for(int i = 0; i<4; i++){
            int next_y = now_y + dy[i];
            int next_x = now_x + dx[i];

            if(next_x < 0 || next_y < 0 || next_y >= n || next_x >= m) {
                continue;
            }
            if(campus[next_y][next_x] != 'X' && !visited[next_y][next_x]) {
                que.push({next_y, next_x});
            }
        }
    }
    if(count == 0) {
        cout << "TT";
        return 0;
    }
    cout << count;
}