/*
 * 입력: 행 R, 열 C / 미로정보
 * 출력: 불이 도달하기 전에 미로 탈출 불가 -> IMPOSSIBLE, 아니면 가장 빠른 탈출 시간
 */
#include <bits/stdc++.h>
using namespace std;

string board[1000];
int dist1[1000][1000]; // 불
int dist2[1000][1000]; // 지훈

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0,1,0,-1};

int main() {
    int r, c;
    cin >> r >> c;

    queue<pair<int, int>> que1; // 불
    queue<pair<int, int>> que2; // 지훈

    for(int i = 0; i<r; i++){
        fill(dist1[i], dist1[i]+c, -1);
        fill(dist2[i], dist2[i]+c, -1);
    }

    for(int i = 0; i<r; i++){
        string s;
        cin >> s;
        board[i] = s;
        for(int j  = 0; j<s.size(); j++){
            if(board[i][j] == 'F'){
                que1.push({i, j});
                dist1[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                que2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    while(!que1.empty()){
        pair<int, int> cur = que1.front(); que1.pop();
        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            que1.push({nx, ny});
        }
    }

    while(!que2.empty()){
        pair<int, int> cur = que2.front(); que2.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            que2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}