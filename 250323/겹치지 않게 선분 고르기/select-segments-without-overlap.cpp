#include <iostream>

using namespace std;

int n;
int x1[15], x2[15];
int now = 0;
int max_cnt = 0;
int min_x = 1000, max_y = 0;

void choice(int num){
    if(num == n){
        return;
    }

    for(int i = num; i < n; i++) {
        // 현재 선분이 선택되지 않은 상태면 선택
        int now_x = x1[i];
        int now_y = x2[i]; // 현재 선분

        // 선택된 거면 다음 거 보기
        if((min_x <= now_x && now_x <= max_y) || (min_x <= now_y && now_y <= max_y)) {
            continue;
        }

        // 선택 안 된 거면 업데이트
        int tmp_x = min_x, tmp_y = max_y;
        if(now_x < min_x) min_x = now_x;
        if(now_y > max_y) max_y = now_y;

        now++;
        if(now > max_cnt) max_cnt = now;

        // 다음 거 선택
        choice(num + 1);

        // 뽑은 거 취소하고
        // 지금이 1,4고 3,4를 취소해야 돼 => 1,2로 만들어야 됨
        // 지금이 1,4고 1,2를 취소해야 돼 => 3,4로
        if(max_y = now_y) {
            max_y = now_x - 1;
        }
        if(min_x = now_x) {
            min_x = now_y + 1;
        }
        now--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    choice(0);

    cout << max_cnt;

    return 0;
}
