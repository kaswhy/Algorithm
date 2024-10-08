/*
 * n개의 자연수 중에서 m개를 고른 수열
 * 고른 수열은 비내림차순 (오름차순)
 *
 * 1. 2 - 1개, 4 - 2개 / 2, 4
 *
 * 2. 1 - 1개, 7 - 1개, 9 - 2개 / 1, 7, 9
 * 1 7
 * 1 9
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8]; // 입력 정보
int ans[8]; // 정답

void func(int cur, int st){
    if(cur == m){
        for(int i = 0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = st; i<n; i++){
        if(tmp != arr[i]) {
            ans[cur] = arr[i];
            tmp = ans[cur];
            func(cur + 1, i + 1);
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

    func(0, 0);
}