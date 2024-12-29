#include <bits/stdc++.h>
using namespace std;

struct rect {int idx; long long int height;};
long long max(long long a, long long b) {
    return a > b ? a: b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int n;
        cin >> n;

        if(n == 0) {
            return 0;
        }

        stack<rect> nums;
        long long int ans = 0;

        for(int i = 0; i<n; i++) {
            int h, idx = i;
            cin >> h;

            while(!nums.empty() && nums.top().height > h) {
                idx = nums.top().idx;
                ans = max(ans, (long long)nums.top().height * (i - idx));
                nums.pop();
            }

            if(nums.empty() || nums.top().height < h) {
                nums.push({idx, h});
            }
        }

        while(!nums.empty()) {
            ans = max(ans, nums.top().height * (n - nums.top().idx));
            nums.pop();
        }
        cout << ans << "\n";
    }
}