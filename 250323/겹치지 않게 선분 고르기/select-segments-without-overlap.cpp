#include <iostream>

using namespace std;

int n;
int x1[15], x2[15];
int now = 0;
int max_cnt = 0;
bool v[1001];

void choice(int num){
    if(num == n){
        return;
    }

    for(int i = num; i < n; i++) {
        // 현재 선분이 선택되지 않은 상태면 선택
        bool is_chosen = false;
        int x = x1[i];
        int y = x2[i];

        for(int j = x; j<=y; j++) {
            if(v[j]) {
                is_chosen = true;
                break;
            }
        }
        if(is_chosen) continue;

        for(int j = x; j<=y; j++) {
            v[j] = true;
        }
        now++;
        if(now > max_cnt) max_cnt = now;

        // 다음 거 선택
        choice(num + 1);

        // 뽑은 거 취소하고
        for(int j = x; j<=y; j++) {
            v[j] = false;
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
