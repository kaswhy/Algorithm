/*
 * 입력: 2차원 배열 행 n, 열 m / 배열 정보
 * 출력: 빙산이 분리되는 최초의 시간
 */
#include <bits/stdc++.h>
using namespace std;

int board[300][300];
bool chk[300][300];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    int bingsan = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] >0 ) bingsan++;
        }
    }

    int cnt = 0;
    while(bingsan > 0){
        int melt = 0;
        for(int i = 0; i<300; i++){
            fill(chk[i], chk[i] + m, false);
        }
        queue<pair<int, int>> que;
        int now = 0;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(!chk[i][j] && board[i][j]){
                    que.push({i, j});
                    chk[i][j] = true;
                    now++;

                    while(!que.empty()){
                        pair<int, int> cur = que.front(); que.pop();

                        int tmp = 0;
                        for(int k = 0; k<4; k++){
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];

                            if(ny <0 || ny >=n || nx <0 || nx>=m)continue;
                            if(board[ny][nx] && !chk[ny][nx]){
                                que.push({ny, nx});
                                chk[ny][nx] = true;
                                now++;
                            }
                            if(!board[ny][nx] && !chk[ny][nx]) tmp++;
                        }

                        if(tmp >= board[cur.first][cur.second]) {
                            board[cur.first][cur.second] = 0;
                            melt++;
                        }
                        else {
                            board[cur.first][cur.second] -= tmp;
                        }
                    }

                    if(now != bingsan){
                        cout << cnt;
                        return 0;
                    }
                }
            }
            if(now == bingsan) break;
        }
        cnt++;
        bingsan -= melt;
    }
    cout << 0;
}
