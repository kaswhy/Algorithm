#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[7];
int ans[7];


void func(int cur){
    if(cur == m){
        for(int i = 0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i<n; i++){
        ans[cur] = arr[i];
        func(cur+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    fill(arr, arr + 7, 10001);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+7);
    func(0);
}