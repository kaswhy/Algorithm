/*
 * 입력: f, s, g, u, d
 * 출력: s층에서 g층으로 가기 위해 눌러야 하는 버튼 수의 최솟값
 *  [조건]
 *  - 빌딩 층: 1 ~ f
 *  - 목표 위치 : g
 *  - 현재 위치 : s
 *  - 엘리베이터를 통해 갈 수 있는 위치: 위로 u, 아래로 d
 *
 *  => 1차원 bfs
 */
#include <bits/stdc++.h>
using namespace std;

int board[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    fill(board, board+f+1, -1);

    queue<int> que;
    que.push(s);
    board[s] += 1;

    while(!que.empty()){
        int now = que.front(); que.pop();

        if(now == g){
            cout << board[now];
            return 0;
        }

        int up = now + u;
        int down = now - d;

        if(up >= 1 && up <= f) {
            if (board[up] < 0) {
                board[up] = board[now] + 1;
                que.push(up);
            }
        }

        if(down >= 1 && down <= f ) {
            if (board[down] <0) {
                board[down] = board[now] + 1;
                que.push(down);
            }
        }
    }
    if(board[g] >= 0) cout << board[g];
    else cout << "use the stairs";
}