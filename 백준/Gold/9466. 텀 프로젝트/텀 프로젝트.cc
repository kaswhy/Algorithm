/*
 * 입력: 테스트케이스 t / 학생수 n / 선택된 학생들의 번호
 * 출력: 프로젝트 팀에 속하지 못한 학생들의 수
 */
#include <bits/stdc++.h>
using namespace std;

int board[100001];
int chk[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        fill(chk, chk+1+n,0);

        for(int i = 1; i<=n; i++){
            cin >> board[i];
        }

        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(chk[i] != 0){
                continue;
            }
            int cur = i;
            while(true) {
                chk[cur] = i;
                cur = board[cur];

                if (chk[cur] == i) {
                    while (chk[cur] != -1) {
                        chk[cur] = -1;
                        cur = board[cur];
                    }
                    break;
                }
                else if(chk[cur] != 0) break;
            }
        }

        for(int i = 1; i<=n; i++){
            if(chk[i] != -1) cnt++;
        }
        cout << cnt << "\n";
    }
}