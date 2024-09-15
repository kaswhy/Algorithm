/*
 * 입력: 탑의 수 N / 탑들의 높이 (1 <= x <= 100,000,000)
 * 출력: 레이저 신호를 수신한 탑들의 번호 (수신하지 못하면 0)
 *  [필요한 것]
 *  - 탑 스택
 *  - 신호받은 탑 배열 (전역변수로 0으로 초기화)
 *
 *  [수도코드]
 *  1. 하나씩 스택에서 pop 하고 현재 숫자 임시 스택에 push
 *  2. 스택의 top 과 비교, 현재 숫자가 작으면 스택의 크기를 신호 배열에 저장, 임시 스택에서 pop
 *  3. 만약에 현재 숫자가 크면 임시 스택에 넣어놓음
 *  4. 다음에 비교할 때 스택 top이랑 계속 비교
 */
#include <bits/stdc++.h>
using namespace std;

int sig[500001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    stack<pair<int, int>> tmp; // idx, value
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    while(s.size() > 1){
        int now = s.top();
        int now_idx = s.size();
        s.pop();

        tmp.push({now_idx, now});
        while(!tmp.empty()){
            int comp_idx = tmp.top().first;
            int comp = tmp.top().second;
            if(comp <= s.top()){
                sig[comp_idx] = s.size();
                tmp.pop();
                continue;
            }
            break;
        }
    }

    for(int i = 1; i<=n; i++){
        cout << sig[i] << " ";
    }
}