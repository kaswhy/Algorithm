#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void func(int cur){
    if(cur == m){
        for(int i = 0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i<n; i++){
        if(cur == 0){
            ans[cur] = arr[i];
            func(cur+1);
        }
        if(cur > 0){
            if(ans[cur-1] <= arr[i]){
                ans[cur] = arr[i];
                func(cur+1);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    fill(arr, arr+8, 10001);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+8);
    func(0);
}