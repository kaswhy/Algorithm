#include <bits/stdc++.h>
using namespace std;

int k;
int arr[13];
int ans[13];
bool isused[13];

void func(int cur){
    if(cur == 6){
        for (int i = 0; i < 6; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < k; i++){
        if (!isused[i]) {
            if (arr[i] >= ans[cur-1]) {
                isused[i] = 1;
                ans[cur] = arr[i];
                func(cur + 1);
                isused[i] = 0;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (true) {
        cin >> k;
        if (k == 0) {
            return 0;
        }
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+k);

        func(0);
        cout << '\n';
    }
}