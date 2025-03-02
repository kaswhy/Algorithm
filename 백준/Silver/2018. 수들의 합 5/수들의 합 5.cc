#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int count = 1, start = 1, end = 1, sum = 1;
    
    while(end != n) {
        if(sum == n) {
            count++;
            end++;
            sum += end;
            continue;
        }
        if(sum > n) {
            sum -= start;
            start++;
            continue;
        }
        end++;
        sum+=end;
    }
    
    cout << count;
}
