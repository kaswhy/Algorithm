#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<char> results;
    
    for(int i =0 ; i<n; i++) {
        cin >> a[i];
    }
    
    stack<int> s;
    int num = 1;
    bool result = true;
    
    for(int i = 0; i<a.size(); i++) {
        int now = a[i];
        
        if(now >= num) {
            while(now >= num) {
                s.push(num++);
                results.push_back('+');
            }
            s.pop();
            results.push_back('-');
            continue;
        }
        int c = s.top();
        s.pop();
        
        if(c > now) {
            cout << "NO";
            result = false;
            break;
        }
        results.push_back('-');
    }
    
    if(result) {
        for(int i = 0; i<results.size(); i++) {
            cout << results[i] << '\n';
        }
    }
}
