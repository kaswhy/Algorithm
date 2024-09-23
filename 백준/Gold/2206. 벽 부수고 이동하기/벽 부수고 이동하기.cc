/*
 * 입력: n, m / 맵 정보
 * 출력: 최단 거리
 * 벽 사용한 개수를 저장하는 배열을 하나 더 써보자
 */
/*
#include <bits/stdc++.h>
using namespace std;

string board[1000];
int dist[1000][1000][2];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1}; // 0 -> 안 깸,  1->깸

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        board[i] = s;
        for(int j = 0; j<n; j++){
            fill(dist[i][j], dist[i][j]+2, -1);
        }
    }

    queue<tuple<int, int, int>> que;
    que.push({0,0,0});
    dist[0][0][0] = 1;

    while(!que.empty()){
        int x, y, broken;
        tie(x, y, broken) = que.front(); que.pop();

        for(int i = 0; i<4; i++){
            int ny = get<0>(cur) + dy[i];
            int nx = get<1>(cur) + dx[i];
            int brick = get<2>(cur);

            if(ny <0 || ny >=n || nx <0 || nx >= m) continue;
            if(dist[ny][nx][0] >= 0 || dist[ny][nx][1] >= 0) continue;
            if(board[])
        }
    }
    cout << -1;
}
 */
/*
 * 입력: n, m / 맵 정보
 * 출력: 최단 거리
 * 벽 사용한 개수를 저장하는 배열을 하나 더 써보자
 */
#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int dist[1000][1000][2];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1}; // 0 -> 안 깸,  1->깸

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    queue<tuple<int, int, int>> que;
    que.push({0,0,0});
    dist[0][0][0] = 1; dist[0][0][0] = 1;

    while(!que.empty()){
        int x, y, brick;
        tie(y, x, brick) = que.front();

        if(y == n-1 && x == m-1){
            cout << dist[n-1][m-1][brick];
            return 0;
        }
        que.pop();

        for(int i = 0; i<4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny <0 || ny >=n || nx <0 || nx >= m) continue;
            if(board[ny][nx]=='0' && dist[ny][nx][brick]==-1){
                dist[ny][nx][brick] = dist[y][x][brick]+1;
                que.push({ny, nx, brick});
            }
            if(!brick && board[ny][nx]=='1' && dist[ny][nx][brick]==-1){
                dist[ny][nx][1] = dist[y][x][brick]+1;
                que.push({ny, nx ,1});
            }
        }
    }
    cout << -1;
}