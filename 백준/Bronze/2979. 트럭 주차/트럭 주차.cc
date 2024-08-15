#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 주차요금 A, B, C / 도착 시간, 떠난 시간
     * 출력: 내야 하는 주차 요금
     * 1. 101짜리 배열 0으로 초기화
     * 2. 도착시간부터 들어온 시간까지 ++
     * 3. 1~max까지 돌면서 sum 추가
     */
    int a , b, c;
    cin >> a >> b >> c;

    vector<int> times(101, 0);
    int max = 0;

    for(int i =0 ; i<3; i++){
        int arrive, leave;
        cin >> arrive >> leave;

        for(int j = arrive + 1; j<=leave; j++){
            times[j]++;
        }

        if(leave > max) max = leave;
    }

    int cnt = 0;
    for(int i = 1; i<=max; i++){
        if(times[i] == 1){
            cnt += a;
            continue;
        }
        if(times[i] == 2){
            cnt += b * 2;
            continue;
        }
        if(times[i] == 3){
            cnt += c * 3;
        }
    }
    cout << cnt;
}