/*
 * 입력: 말처럼 움직일 수 있는 횟수 k / w, h / 정보
 * 출력: 원숭이 동작수의 최솟값
 */
#include <bits/stdc++.h>
using namespace std;

int board[200][200];
int dist[31][200][200];

int hy[8] = {-2, -1,1,2,2,1,-1,-2};
int hx[8] = {1, 2, 2, 1, -1,-2,-2,-1};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int k;
    cin >> k;

    int w, h;
    cin >> w >> h;

    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            cin >> board[i][j];
            dist[0][i][j] = 0;
        }
    }

    queue<tuple<int, int, int>> que;
    if(!board[0][0]) {
        que.push({0, 0, 0});
        dist[0][0][0] = 1;
    }

    while(!que.empty()){
        int qk, qy, qx;
        tie(qk, qy, qx) = que.front(); que.pop();

        if(qy == h-1 && qx == w-1){
            cout << dist[qk][h-1][w-1] - 1;
            return 0;
        }

        if(qk < k){
            for(int i = 0; i<8; i++){
                int ny = qy + hy[i];
                int nx = qx + hx[i];

                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(!board[ny][nx] && !dist[qk+1][ny][nx]){
                    dist[qk+1][ny][nx] = dist[qk][qy][qx] + 1;
                    que.push({qk + 1, ny, nx});
                }
            }
        }
        for(int i = 0; i<4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (!board[ny][nx] && !dist[qk][ny][nx]) {
                dist[qk][ny][nx] = dist[qk][qy][qx] + 1;
                que.push({qk, ny, nx});
            }
        }
    }
    cout << -1;
}