#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int count = 0;
    int i = 0;
    int j = n-1;
    
    while(i < j) {
        if(a[i] + a[j] < m) {
            i++;
            continue;
        }
        if(a[i] + a[j] > m) {
            j--;
            continue;
        }
        count++;
        i++;
        j--;
    }
    
    cout << count;
}
