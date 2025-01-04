#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> pos; // 양수 저장
    priority_queue<int> neg; // 음수 저장
    while(n--){
        int x;
        cin >> x;
        if(x > 0) {
            pos.push(x);
            continue;
        }
        if(x < 0){
            neg.push(x);
            continue;
        }
        if(pos.empty() && neg.empty()){
            cout << 0 << "\n";
            continue;
        }
        if(pos.empty() && !neg.empty()) {// 음수만 있는 경우
            cout << neg.top() << "\n";
            neg.pop();
            continue;
        }
        if(!pos.empty() && neg.empty()){ // 양수만 있는 경우
            cout << pos.top() << "\n";
            pos.pop();
            continue;
        }
        // 둘 다 존재하는 경우
        if(abs(pos.top()) == abs(neg.top())) {
            cout << neg.top() << "\n";
            neg.pop();
            continue;
        }
        if(abs(pos.top()) < abs(neg.top())) {
            cout << pos.top() << "\n";
            pos.pop();
            continue;
        }
        cout << neg.top() << "\n";
        neg.pop();
    }
}