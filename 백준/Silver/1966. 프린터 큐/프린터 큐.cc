#include <iostream>
#include <queue>
using namespace std;

int main(){
    /*
     * 입력:테스트 케이스 t / 문서 개수 n, 알고싶은 문서 번호 m / 현재 큐 imp
     * 출력:
     * 1. 큐의 front의 중요도 확인
     * 2. 나머지 문서 중 현재 문서보다 중요도가 높은 게 있으면 큐의 맨 마지막에 재배치
     *  - max 값을 찾음
     *  - max 값이 현재 값보다 크면 현재 값 뒤로 배치
     *  -> 10000번
     */
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, imp;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> printer;
        for(int i =0; i<n; i++){
            cin >> imp;
            q.push({imp, i});
            printer.push(imp);
        }

        int ans = 1;
        while(true){
            int now = q.front().first;
            int nth = q.front().second;
            if(now != printer.top()){
                q.pop();
                q.push({now, nth});
                continue;
            }
            else {
                if (nth == m) break;
                else {
                    q.pop();
                    printer.pop();
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}