/*
 * 입력: 테스트케이스 T / 한변의 길이 / 나이트가 현재 있는 칸 / 이동하려고 하는 칸
 * 출력: 나이트가 최소 몇 번만에 이동할 수 있는지
 */
#include <bits/stdc++.h>
using namespace std;

int board[300][300];
int dist[300][300];

int dy[8] = {-2, -1, 1,2, 2,1, -1,-2};
int dx[8] = {1, 2, 2, 1, -1,-2,-2,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int l;
        cin >> l;

        for(int i = 0; i<l; i++){
            fill(board[i], board[i] + l, 0);
            fill(dist[i], dist[i] + l, -1);
        }

        queue<pair<int, int>> que;

        int y, x;
        cin >> y >> x; // 현재 나이트 위치

        int ry, rx;
        cin >> ry >> rx; // 목표 나이트 위치

        que.push({y, x});
        dist[y][x] ++;

        while(!que.empty()){
            pair<int, int> cur = que.front(); que.pop();

            if(cur.first == ry && cur.second == rx){
                break;
            }

            for(int i = 0; i<8; i++){
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if(ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
                if(dist[ny][nx] >=0 ) continue;
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                que.push({ny, nx});
            }
        }

        cout << dist[ry][rx] << "\n";
    }

}