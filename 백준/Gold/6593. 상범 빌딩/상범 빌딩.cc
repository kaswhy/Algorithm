/*
 * 입력: 층수 l, 행 r, 열 c / 빌딩 정보(S-시작, E-출구, '#'-통행불가, '.'-가능)
 * 출력: 탈출 가능 시간
 */
#include <bits/stdc++.h>
using namespace std;

string board[30][30];
int dist[30][30][30];

int dz[6] = {0,0,0,0,-1,1}; // 동, 서, 남, 북, 상, 하
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {1,-1,0,0,0,0};

int main() {
    while(true){
        int l, r, c;
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0){
            return 0;
        }

        queue<tuple<int, int,int>> que;
        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                string s;
                cin >> s;
                board[i][j] = s;
                fill(dist[i][j], dist[i][j] + c, -1);

                for(int k = 0; k<s.size(); k++){
                    if(s[k] == 'S'){
                        que.push(make_tuple(i, j, k));
                        dist[i][j][k]++;
                    }
                }
            }
        }

        bool exit = false;
        while(!que.empty()){
            tuple<int, int, int> cur = que.front(); que.pop();

            if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E'){
                cout << "Escaped in " << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] << " minute(s).\n";
                exit = true;
                break;
            }

            for(int i = 0; i<6; i++){
                int nz = get<0>(cur) + dz[i];
                int ny = get<1>(cur) + dy[i];
                int nx = get<2>(cur) + dx[i];

                if(nz <0 || nz>=l || ny <0 || ny >= r || nx <0 || nx>=c) continue;
                if(board[nz][ny][nx] == '#' || dist[nz][ny][nx] >= 0) continue;
                dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                que.push(make_tuple(nz, ny, nx));
            }
        }

        if(!exit) cout << "Trapped!\n";


    }
}