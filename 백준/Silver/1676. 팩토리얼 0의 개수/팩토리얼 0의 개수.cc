#include <iostream>
using namespace std;

int main() {
    /*
     * 입력: n
     * 출력: 0의 개수
     * n!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램
     *  1. 분류
     *      - 0 ~ 4 : 0 (0,1,2,6,24)
     *      - 5 (120), 6 (720), 7 (5040), 8(40320), 9 (362880) -> 1
     *      - 10 ~ 14 -> 2
     *      - 15 ~ 19 -> 3
     *      => 100으로 나눠지면 2씩 count, 그외 5의 배수는 1씩 count
     *
     */
    int n, count = 0;
    cin >> n;

    while(n>=5){
        if ((n / 5) % 25 == 0){
            count += 3;
            n-=5;
            continue;
        }
        else if((n / 5) % 5 == 0) {
            count += 2;
            n-=5;
            continue;
        }
        count++;
        n-=5;
    }

    cout << count;
}