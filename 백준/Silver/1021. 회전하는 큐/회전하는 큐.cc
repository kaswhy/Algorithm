/*
 * 입력: 큐의 크기 n, 뽑으려는 수 m / 뽑으려고 하는 수의 위치가 순서대로
 * 출력: 원소를 주어진 순서대로 뽑아내는 데 드는 2, 3번 연산의 최솟값
 *  [조건]
 *  - 양방향 순환 큐
 *  - 가능한 연산
 *      1) 첫 번째 원소 뽑아냄
 *      2) 왼쪽으로 한 칸 이동 (pop_front, push_back)
 *      3) 오른쪽으로 한 칸 이동 (pop_back, push_front)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    deque<int> deq;
    for(int i = 0; i<n; i++){
        deq.push_back(i+1);
    }

    vector<int> com;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        com.push_back(x);
    }

    int cnt = 0, fst = 0;
    for(int now : com){
        fst = 0;
        int mid = deq.size() / 2;
        for(int i = 0; i <= mid; i++){
            if(*(deq.begin()+i) == now){
                fst = 1;
                break;
            }
        }

        if(fst){
            while(deq.front() != now) {
                deq.push_back(deq.front());
                deq.pop_front();
                cnt++;
            }
            deq.pop_front();
        }
        else {
            while(deq.front() != now) {
                deq.push_front(deq.back());
                deq.pop_back();
                cnt++;
            }
            deq.pop_front();
        }
    }

    cout << cnt;
}