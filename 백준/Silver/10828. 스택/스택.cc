/*
 * 입력: 명령 수 n / 명령
 * 출력: 출력해야 할 시, 한 줄에 하나씩 출력
 * STL stack으로 구현
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    while(n--){
        string com;
        cin >> com;

        if(com == "push"){
            int x;
            cin >> x;
            s.push(x);
            continue;
        }
        if(com == "pop"){
            if(s.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
            s.pop();
            continue;
        }
        if(com == "size"){
            cout << s.size() << "\n";
            continue;
        }
        if(com == "empty"){
            if(s.empty()){
                cout << 1 << "\n";
                continue;
            }
            cout << 0 << "\n";
            continue;
        }
        if(com == "top"){
            if(s.empty()){
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
            continue;
        }
    }
}