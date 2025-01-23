#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        cout << binary_search(v.begin(), v.end(), x) << " ";
    }
}