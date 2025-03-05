#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0; // "아름다운 수" 개수
vector<int> nums;

void choice(int num) {
    if(num == n+1){
        int now = nums[0], num_cnt = 1;

        for(int i = 1; i<n; i++) {
             // 지금 나온 수가 체크하고 있는 수랑 다른 경우 => 아름다운 수인지 검증
             if(now != nums[i]) {
                if(num_cnt % now != 0) {
                    return;
                }
                now = nums[i];
                num_cnt = 1;
                continue;
             }
            // 같은 수면 => 나온 횟수만 늘림
            num_cnt++;
        }
        if(num_cnt % now == 0) {
            cnt++;
        }
        return;
    }

    for(int i = 1; i<=4; i++){
        nums.push_back(i);
        choice(num+1);
        nums.pop_back();
    }

}

int main() {
    cin >> n;
    choice(1);
    cout << cnt;
    return 0;
}
