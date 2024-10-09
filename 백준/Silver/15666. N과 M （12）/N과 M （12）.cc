#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void func(int cur, int st){
    if (cur == m) {
       for (int i = 0; i < m; i++) {
           cout << ans[i] << ' ';
       }
       cout << '\n';
       return;
    }

    int tmp = 0;
    for (int i = st; i < n; i++) {
        if (tmp != arr[i]){
            ans[cur] = arr[i];
            tmp = ans[cur];
            func(cur + 1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    func(0, 0);
}