/*
 * 입력: 가로 크기 n, 세로 크기 m / 그림 정보
 * 출력: 그림 개수, 가장 넓은 그림의 넓이
 */
#include <bits/stdc++.h>
using namespace std;

int board[500][500];
bool chk[500][500];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x;
            cin >> x;
            board[i][j] = x;
        }
    }

    queue<pair<int, int>> que;

    int cnt = 0, max = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] && !chk[i][j]){
                cnt++;
                int tmp = 1;
                que.push({i, j});
                chk[i][j] = true;

                while(!que.empty()){
                    pair<int, int> cur =  que.front(); que.pop();

                    for(int k = 0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                            if(board[nx][ny] && !chk[nx][ny]) {
                                que.push({nx, ny});
                                chk[nx][ny] = true;
                                tmp++;
                            }
                        }
                    }
                }
                if(tmp > max) max = tmp;
            }
        }
    }

    cout << cnt << "\n";
    cout << max << "\n";
}