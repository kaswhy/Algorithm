#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    set<int> s;

    while(n--){
        int x;
        cin >> x;
        s.insert(x);
    }
    

    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;

        if(s.find(x) == s.end()) cout << 0 << " ";
        else cout << 1 << " ";
    }
}