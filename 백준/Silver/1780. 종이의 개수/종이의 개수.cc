/*
 * 입력: n / 정보
 * 출력: -1, 0, 1로만 채워진 종이의 개수
 * 0 1 2    9 10 11     18 19 20
 * 3 4 5    12 13 14    21 22 23
 * 6 7 8    15 16 17    24 25 26
 *
 * 9,0,0 / 3,0,0 /  100 101 102 110 111 112 120 121 122
 *       / 301 / 101 102
 */
#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int arr[3];
int n;

bool chk(int x, int r, int c){
    for(int i = r; i<r+x; i++){
        for(int j = c; j<c+x; j++){
            if(board[i][j]!= board[r][c]){
                return false;
            }
        }
    }
    return true;
}

void func(int x, int r, int c){
    if(chk(x, r, c)){
        arr[board[r][c]+1] += 1;
        return;
    }
    int nx = x / 3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            func(nx, nx*i + r, nx*j +c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
        }
    }

    func(n, 0, 0);

    for(int x : arr){
        cout << x << "\n";
    }
}