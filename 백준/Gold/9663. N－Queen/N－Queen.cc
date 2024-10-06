#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool isused1[15];
bool isused2[30];
bool isused3[30];

// cur번째 행에 말을 배치하는 법
void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i = 0; i<n; i++){
        if(!isused1[i] && !isused2[cur + i] && !isused3[cur - i + n - 1]){
            isused1[i] = 1;
            isused2[cur+i] = 1;
            isused3[cur - i + n -1] = 1;
            func(cur + 1);
            isused1[i] = 0;
            isused2[cur+i] = 0;
            isused3[cur - i + n -1] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}