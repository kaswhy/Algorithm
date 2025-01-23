#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;;

    vector<int> v(k+1, 0);
    v[0] = 1;

    while(n--){
        int x;
        cin >> x;

        for(int i = x; i<=k; i++){
            v[i] += v[i-x];
        }
    }
    cout << v[k];
}
