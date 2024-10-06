#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[7];

void func(int cur){
    if(cur == m){
        for(int i = 0; i<m; i++){
            cout << board[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i<=n; i++){
        board[cur] = i;
        func(cur + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    func(0);
}