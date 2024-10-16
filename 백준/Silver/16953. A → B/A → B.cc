#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    queue<pair<int, int>> que;
    que.push({b, 0});

    while(!que.empty()){
        pair<int, int> cur = que.front(); que.pop();

        int now = cur.first;
        int cost = cur.second;

        if (now == a) {
            cout << cost + 1;
            return 0;
        }

        if (now < a) {
            cout << -1;
            return 0;
        }

        if (now % 2 == 0) {
            que.push({now/2, cost+1});
            continue;
        }
        if (now % 10 != 1) {
            break;
        }
        que.push({(now-1)/10, cost+1});
    }
    cout << -1;
}