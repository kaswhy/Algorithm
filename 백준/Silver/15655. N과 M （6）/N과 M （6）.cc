#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8]; // 입력 배열
int ans[8]; // 정답이 되는 배열
bool isused[8];

void func(int cur){
    if(cur == m){
        for(int i = 0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i<n; i++){ // 1, 7, 8, 9
        if(!isused[i]){
            if(cur > 0){
                if(arr[i] < ans[cur-1]) continue;
            }
            isused[i] = 1;
            ans[cur] = arr[i];
            func(cur+1);
            isused[i] = 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    fill(arr, arr+8, 100001);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+8);
    func(0);
}