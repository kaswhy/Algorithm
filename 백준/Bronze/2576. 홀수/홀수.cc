#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v(7);
    int cnt = 0, min = 100;

    for(int i = 0; i<7; i++){
        cin >> v[i];
        if(v[i] % 2 == 1){
            cnt += v[i];
            if(v[i] < min) {
                min = v[i];
            }
        }
    }

    if(cnt == 0) {
        cout << -1;
        return 0;
    }

    cout << cnt << "\n";
    cout << min;
}