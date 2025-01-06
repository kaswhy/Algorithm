#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int y = 0, m = 0;
    for(int i = 0; i<n; i++){
        int now;
        cin >> now;
        y += ((now / 30) + 1) * 10;
        m += ((now / 60) + 1) * 15;
    }

    if(y == m) {
        cout << "Y M " << y;
    }
    if(y < m) {
        cout << "Y " << y;
    }
    if(m<y) {
        cout << "M " << m;
    }
}