/*
 * 0,2
 * 1,1 / 1,3
 * 2,0 / 2, 1 / 2, 2 / 2, 3 / 2, 4
 *
 * 3 -> 1개
 * 6 -> 3개
 * 12 -> 9개
 * 24 -> 27개
 */
#include <bits/stdc++.h>
using namespace std;

char board[3072][6144];

void func(int n, int r, int c){
    if(n==3){
        for(int i = 0; i<3; i++){ // 0 -> 0 / 1 -> 0, 1 / 2 -> 0, 1, 2
            for(int j = 0; j<=i; j++){
                if(i == 1 && j == 0) continue;
                board[r+i][c+j] = '*';
                board[r+i][c-j] = '*';
            }
        }
        return;
    }
    int half = n / 2;
    func(half, r, c); // 24, 0, 23;
    func(half, r + half, c - half);
    func(half, r + half, c + half);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    func(n, 0, n-1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n*2; j++){
            if(board[i][j] != '*') cout << ' ';
            else cout << '*';
        }
        cout << "\n";
    }
}