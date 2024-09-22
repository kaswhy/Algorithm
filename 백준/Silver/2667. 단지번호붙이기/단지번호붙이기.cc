/*
 * 입력: 지도 크기 N / 지도 정보
 * 출력: 총 단지 수 / 각 단지 내 집의 수 오름차순으로
 */
#include <bits/stdc++.h>
using namespace std;

string board[25];
int chk[25][25];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        board[i] = s;
    }

    queue<pair<int, int>> que;
    vector<int> part;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == '1' && !chk[i][j]){
                int tmp = 1;
                que.push({i, j});
                chk[i][j] = true;

                while(!que.empty()){
                    pair<int,int> cur = que.front(); que.pop();

                    for(int k = 0; k<4; k++){
                        int ny = cur.first + dy[k];
                        int nx = cur.second + dx[k];
                        if(ny < 0 || ny >= n || nx <0 || nx >= n) continue;
                        if(board[ny][nx] == '0' || chk[ny][nx])continue;
                        chk[ny][nx] = true;
                        tmp++;
                        que.push({ny, nx});
                    }
                }

                part.push_back(tmp);
            }
        }
    }
    cout << part.size() << '\n';
    sort(part.begin(), part.end());
    for(int x:part){
        cout << x << "\n";
    }

}