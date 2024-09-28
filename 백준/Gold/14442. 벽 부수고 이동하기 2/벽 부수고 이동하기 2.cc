/*
 * 입력: n, m, k / 맵 정보
 * 출력: 최단 거리
 */
#include <bits/stdc++.h>
using namespace std;

string board[1000];
int dist[11][1000][1000];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i<n; i++){
        cin >> board[i];
    }

    queue<tuple<int, int, int>> que;
    que.push({0,0,0});
    dist[0][0][0] = 1;

    while(!que.empty()){
        int qk, qy, qx;
        tie(qk, qy, qx) = que.front(); que.pop();

        if(qy == n-1 && qx == m-1){
            cout << dist[qk][qy][qx];
            return 0;
        }

        if(qk < k){
            for(int i = 0; i<4; i++){
                int ny = qy + dy[i];
                int nx = qx + dx[i];

                if(ny < 0 || ny >= n || nx <0 || nx >=m) continue;
                if(board[ny][nx] == '1'){
                    if(dist[qk+1][ny][nx]) continue;
                    dist[qk+1][ny][nx] = dist[qk][qy][qx] + 1;
                    que.push({qk+1, ny, nx});
                    continue;
                }
                if(dist[qk][ny][nx]) continue;
                dist[qk][ny][nx] = dist[qk][qy][qx] + 1;
                que.push({qk, ny, nx});
            }
            continue;
        }
        for(int i = 0; i<4; i++){
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if(ny < 0 || ny >= n || nx <0 || nx >=m) continue;
            if(board[ny][nx] == '1') continue;
            if(dist[qk][ny][nx]) continue;
            dist[qk][ny][nx] = dist[qk][qy][qx] + 1;
            que.push({qk, ny, nx});
        }
    }
    cout << -1;
}