/*
 * 입력: 명령 수 n / 명령
 * 출력: 출력해야 할 시, 한 줄에 하나씩 출력
 * 직접 구현(배열, 인덱스 변수)하여 스택 구현
 */
#include <bits/stdc++.h>
using namespace std;

const int MX = 10000;
int dt[MX];
int pos = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    while(n--){
        string com;
        cin >> com;

        if(com == "push"){
            int x;
            cin >> x;
            dt[pos++] = x;
            continue;
        }
        if(com == "pop"){
            if(!pos){
                cout << -1 << "\n";
                continue;
            }
            cout << dt[pos-1] << "\n";
            pos--;
            continue;
        }
        if(com == "size"){
            cout << pos << "\n";
            continue;
        }
        if(com == "empty"){
            if(!pos){
                cout << 1 << "\n";
                continue;
            }
            cout << 0 << "\n";
            continue;
        }
        if(com == "top"){
            if(!pos){
                cout << -1 << "\n";
                continue;
            }
            cout << dt[pos-1] << "\n";
            continue;
        }
    }
}