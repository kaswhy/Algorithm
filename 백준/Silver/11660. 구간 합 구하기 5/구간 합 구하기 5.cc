#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1024][1024];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int x;
            cin >> x;
            if(j == 0) arr[i][j] = x;
            else arr[i][j] = arr[i][j-1] + x;
        }
    }

    while(m--){
        int tmp = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1 - 1; i <= x2 -1; i++) {
            tmp += arr[i][y2-1];
            if(y1 > 1) tmp -= arr[i][y1-2];
        }
        cout << tmp << '\n';
    }
}