#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int a, b;
    cin >> a >> b;

    if(a < b) {
        cout << b-a-1 << "\n";
        for(unsigned long long int i = a + 1; i < b; i++){
            cout << i << " ";
        }
    } 
    if(a > b) {
        cout << a-b-1 << "\n";
        for(unsigned long long int i = b + 1; i < a; i++) {
            cout << i << " ";
        }
    }
    if (a == b) {
        cout << 0 << "\n";
    }
}