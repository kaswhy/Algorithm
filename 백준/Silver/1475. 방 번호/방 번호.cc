/*
 * 입력: 방 번호 N (1 <= N <= 1,000,000)
 * 출력: 필요한 세트의 개수
 * 10칸짜리 배열 만들어놓고 한 글자씩 읽으면서 ++
 * 6, 9는 더해서 /2
 */
#include <bits/stdc++.h>
using namespace std;

int nums[10];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;

    int max = 0;
    for(char i : s){
        nums[i-'0']++;

        if (i - '0' != 6 && i - '0' != 9) {
            if (nums[i - '0'] > max) {
                max = nums[i - '0'];
            }
            continue;
        }
        int tmp = nums[6] + nums[9];
        if (tmp % 2) {
            tmp /= 2;
            tmp ++;
        }
        else tmp /=2;
        if(tmp > max) {
            max = tmp;
        }
    }

    cout << max;
}