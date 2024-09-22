/*
 * 입력: 테스트케이스 / 빌딩 지도의 너비, 높이 / 빌딩 지도
 * 출력: 빌딩을 탈출하는 데 가장 빠른 시간
 * -> BFS(시작점이 여러 개인 경우 + 시작점이 두 종류인 경우)
 */
#include <bits/stdc++.h>
using namespace std;

string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];

int dy[4] = {-1, 0, 1,0};
int dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;

        queue<pair<int, int>> que1; // 불
        queue<pair<int, int>> que2; // 상근

        for(int i = 0; i<h; i++){
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);

            string s;
            cin >> s;
            board[i] = s;

            for(int j = 0; j<w; j++){
                if(board[i][j] == '*'){
                    que1.push({i, j});
                    dist1[i][j]++;
                }
                if(board[i][j]=='@'){
                    que2.push({i, j});
                    dist2[i][j]++;
                }
            }
        }

        while(!que1.empty()){
            pair<int, int> cur = que1.front(); que1.pop();

            for(int i = 0; i<4; i++){
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(board[ny][nx] == '#' || dist1[ny][nx] >= 0) continue;
                dist1[ny][nx] = dist1[cur.first][cur.second] + 1;
                que1.push({ny, nx});
            }
        }

        int suc = 0;
        while(!que2.empty()){
            pair<int, int> cur = que2.front(); que2.pop();

            for(int i = 0; i<4; i++){
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if(ny < 0 || ny >= h || nx < 0 || nx >= w){
                    cout << dist2[cur.first][cur.second] + 1 << "\n";
                    suc = 1;
                    break;
                }
                if(board[ny][nx] != '.' || dist2[ny][nx] >= 0 ) continue;
                if(dist2[cur.first][cur.second] + 1 >= dist1[ny][nx] && dist1[ny][nx] >= 0) continue;
                dist2[ny][nx] = dist2[cur.first][cur.second] + 1;
                que2.push({ny, nx});
            }
            if(suc) break;
        }
        if(!suc) cout << "IMPOSSIBLE\n";
    }
}