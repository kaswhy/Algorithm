#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n, m;
    cin >> n >> m;

    vector<long> v(n+1, 0);
    vector<long> sums(n+1, 0);
    for(int i = 1; i<=n; i++) {
        cin >> v[i];
        sums[i] = sums[i-1] + v[i];
    }

    long answer = 0;
    vector<long> remainders(m, 0);
    for(int i = 1; i<=n; i++){
        long remainder = sums[i] % m;

        if(remainder == 0) {
            answer++;
        }
        remainders[remainder]++;
    }

    for(int i = 0; i<m; i++){
        if(remainders[i] > 1) {
            answer +=  (remainders[i] * (remainders[i] - 1) / 2);
        }
    }

    cout << answer << "\n";
}
