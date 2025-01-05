#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<pair<int, int>> deq;

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        deq.push_back({num, i+1});
    }

    while(!deq.empty()){
        int cur = deq.front().first;
        cout << deq.front().second << " "; deq.pop_front();

        if(deq.empty()) break;

        if(cur > 0){
            for(int i = 0; i<cur-1; i++){
                deq.push_back(deq.front());
                deq.pop_front();
            }
            continue;
        } else {
            for (int i = 0; i < (-1) * cur; i++) {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
}