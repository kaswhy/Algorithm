/*
 * 입력: 상자 크기 m, n, h / 토마토 정보
 * 출력: 토마토가 모두 익을 때까지 걸리는 시간
 */
#include <bits/stdc++.h>
using namespace std;

int board[100][100][100];
int dist[100][100][100];

int dz[6] = {-1, 1, 0,0,0,0}; // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dy[6] = {0,0,0,0,-1,1};
int dx[6] = {0,0,-1,1,0,0};

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    queue<tuple<int, int, int>> que;
    for(int i = 0; i<h; i++){ // z축
        for(int j = 0; j<n; j++){ // y축
            for(int k = 0; k<m; k++){ // x축
                int x;
                cin >> x;
                board[i][j][k] = x;

                if(x == 1){
                    que.push(make_tuple(i, j, k));
                }
                if(x == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    int cnt = 0;
    while(!que.empty()){
        tuple<int, int, int> cur = que.front(); que.pop();

        for(int i = 0; i<6; i++) {
            int nz = get<0>(cur) + dz[i];
            int ny = get<1>(cur) + dy[i];
            int nx = get<2>(cur) + dx[i];

            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (dist[nz][ny][nx] >= 0 || board[nz][ny][nx] == -1) continue;
            dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            cnt = dist[nz][ny][nx];
            que.push(make_tuple(nz, ny, nx));
        }
    }

    for(int i = 0; i<h; i++){ // z축
        for(int j = 0; j<n; j++){ // y축
            for(int k = 0; k<m; k++){ // x축
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << cnt;
}