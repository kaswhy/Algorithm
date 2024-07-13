#include <iostream>
using namespace std;

int main() {
    /*
     * 입력: 자연수 N
     * 출력: 가장 작은 생성자 구하기®
     * 어떤 수 X의 분해합 = X + X를 이루는 각 자리수 합 -> 요 분해합을 만드는 X가 생성자
     * 어떤 경우에는 생성자가 없을 수도 있고, 여러 개일 수도 있다.
     *  -> 생성자는 분해합보다 무조건 작음
     *  => 0부터 X-1 까지 분해합을 계속 구함. 해당 분해합이 생성자와 같으면 리턴.
     *  243 % 10 = 3 -> 24 / 10 = 24 -> 24 % 10 = 4 -> 24 / 10= 2 -> 2 % 10 = 2 -> 2/ 10= 0
     */
    int N, constructor = 0; // N은 주어진 분해합 -> 얘의 생성자를 찾아야 함
    cin >> N;

    for (int i = 0; i< N; i++) {
        int tmp = i, count = i; // tmp는 생성자, count는 분해합

        while(tmp != 0) {
            count += tmp % 10;
            tmp /= 10;
        }

        if(count == N){
            constructor = 1;
            cout << i;
            break;
        }
    }

    if(constructor == 0) {
        cout << 0;
    }
}