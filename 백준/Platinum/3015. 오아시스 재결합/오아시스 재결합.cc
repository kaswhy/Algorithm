#include <bits/stdc++.h>
using namespace std;

int arr[500000];

struct person {
    int height;
    int nums;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    stack<person> s;
    long long cnt = 0;
    for(int i = 0; i<n; i++){
        int now, same_height = 1;
        cin >> now;

        while(!s.empty() && s.top().height < now) {
            cnt += s.top().nums;
            s.pop();
        }

        if(!s.empty()) {
            if(s.top().height == now) {
                cnt += s.top().nums;
                same_height = s.top().nums + 1;

                if(s.size() > 1) {
                    cnt++;
                }
                s.pop();
            } else {
                cnt++;
            }
        }
        s.push({now, same_height});
    }

    cout << cnt;
}