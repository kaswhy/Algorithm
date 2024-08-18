#include <iostream>
#include <queue>
using namespace std;

int main() {
    /*
     * 입력: 연산 개수 N / 연산 정보
     * 출력: 입력이 0일 때 그에 대한 정보
     * -> priority queue로 구현
     */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0){
            if(min_heap.empty()){
                cout << 0 << "\n";
                continue;
            }
            cout << min_heap.top() << "\n";
            min_heap.pop();
            continue;
        }
        min_heap.push(x);
    }
}