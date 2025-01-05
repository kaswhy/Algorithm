#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 1;
    stack<int> s;
    while(n--){
        int x;
        cin >> x;

        if(x == cnt) cnt++;
        else s.push(x);

        while(!s.empty() && s.top() == cnt) {
            s.pop();
            cnt++;
        }
    }

    if(s.empty()) cout << "Nice";
    else cout << "Sad";
    return 0;
}