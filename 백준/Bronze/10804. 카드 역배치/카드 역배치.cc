#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v(21, 0);
    for(int i = 1; i<21; i++){
        v[i] = i;
    }

    for(int i = 0; i<10; i++){
        int a, b;
        cin >> a >> b;

        vector<int> tmp;
        for(int j = b; j >= a; j--){
            tmp.push_back(v[j]);
        }
        for(int j = a; j<=b; j++){
            v[j] = tmp[j-a];
        }
    }

    for(int i = 1; i<=20; i++){
        cout << v[i] << " ";
    }
}
