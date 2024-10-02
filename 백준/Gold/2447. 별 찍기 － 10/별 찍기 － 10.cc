#include <bits/stdc++.h>
using namespace std;

char board[2200][2200];

void func(int n, int r, int c){
    if(n==1){
        board[r][c] = '*';
        return;
    }
    int third = n / 3;
    for(int i = 0; i<3; i++){
        for(int j =0; j<3; j++){
            if(i==1 && j==1){
                continue;
            }
            func(third, third * i + r, third * j + c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    func(n, 0, 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == '*'){
                cout <<'*';
            }
            else cout << ' ';
        }
        cout << "\n";
    }
    
}