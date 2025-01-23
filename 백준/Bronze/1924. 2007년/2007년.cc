#include <bits/stdc++.h>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    int cnt = 0;
    for(int i = 1; i<x; i++){
        cnt += month[i];
    }
    cnt += y;

    switch ((cnt-1) % 7){
        case 0:
            cout << "MON";
            break;
        case 1:
            cout << "TUE";
            break;
        case 2:
            cout << "WED";
            break;
        case 3:
            cout << "THU";
            break;
        case 4:
            cout << "FRI";
            break;
        case 5:
            cout << "SAT";
            break;
        case 6:
            cout << "SUN";
            break;
    }
}