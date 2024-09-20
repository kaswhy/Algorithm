/*
 * 입력: N / 그림 정보
 * 출력: 적록색약 아닌 사람이 봤을 때 구역 개수 / 적록색약인 사람이 봤을 때 구역 개수
 * 2중 for문 돌면서 시작, 큐를 두개, chk 배열도 두개로 하기
 */
#include <bits/stdc++.h>
using namespace std;

string board[100];
bool chk1[100][100];
bool chk2[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0,1,0,-1};

int main() {
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<pair<int, int>> que1;
    queue<pair<int, int>> que2;

    int cnt1= 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(chk1[i][j]) continue;
            que1.push({i, j});
            chk1[i][j] = true;
            cnt1++;

            while(!que1.empty()){
                pair<int, int> cur = que1.front(); que1.pop();

                for(int k = 0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx <0 || nx >=n || ny <0 || ny >=n) continue;
                    if(chk1[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;
                    chk1[nx][ny] = true;
                    que1.push({nx, ny});
                }
            }
        }
    }

    int cnt2= 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(chk2[i][j]) continue;
            que2.push({i, j});
            chk2[i][j] = true;
            cnt2++;

            while(!que2.empty()){
                pair<int, int> cur = que2.front(); que2.pop();

                for(int k = 0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx <0 || nx >=n || ny <0 || ny >=n) continue;
                    if(chk2[nx][ny]) continue;
                    if(board[cur.first][cur.second] == 'B'){
                        if(board[nx][ny] != 'B') continue;
                        chk2[nx][ny] = true;
                        que2.push({nx, ny});
                        continue;
                    }
                    if(board[nx][ny] == 'B') continue;
                    chk2[nx][ny] = true;
                    que2.push({nx, ny});
                }
            }
        }
    }

    cout << cnt1 << " " << cnt2;

}
