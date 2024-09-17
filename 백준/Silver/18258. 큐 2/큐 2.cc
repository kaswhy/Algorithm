#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    queue<int> q;

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            int x;
            cin >> x;
            q.push(x);
            continue;
        }
        if(s=="pop"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
            continue;
        }
        if(s=="size"){
            cout << q.size() << "\n";
            continue;
        }
        if(s=="empty"){
            if(q.empty()){
                cout << "1\n";
                continue;
            }
            cout << "0\n";
            continue;
        }
        if(s=="front"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            continue;
        }
        if(s=="back"){
            if(q.empty()){
                cout << "-1\n";
                continue;
            }
            cout << q.back() << "\n";
            continue;
        }
    }
}