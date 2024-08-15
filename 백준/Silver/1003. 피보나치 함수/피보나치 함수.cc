#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 테스트케이스 T / N (0 ~ 40)
     * 출력: 0이 출력되는 횟수, 1이 출력되는 횟수
     *  n이 0이면 0 출력, 1이면 1 출력, 그 외는 재귀적 호출-> f(n-1) + f(n-2)
     *  fib(0) : 1 0 -> fib(0)
     *  fib(1) : 0 1 -> fib(1)
     *  fib(2) : 1 1 -> fib(1) + fib(0)
     *  fib(3) : 1 2 -> fib(2) + fib(1)
     *  fib(4) : 2 3
     *  fib(5) : 3 5
     *  fib(6) : 5 8
     *      => fib(n) = fib(n-1) + fib(n-2)
     *      -> n = 0, 1 저장해놓고 2~40까지 39번 반복하면서 미리 배열 채우기
     */
    int t, n;
    cin >> t;

    vector<pair<int, int>> fibs(41);

    fibs[0] = {1, 0};
    fibs[1] = {0, 1};

    for(int i = 2; i<=40; i++){
        int first = fibs[i-1].first + fibs[i-2].first;
        int second = fibs[i-1].second + fibs[i-2].second;
        fibs[i] = {first, second};
    }

    while(t--){
        cin >> n;
        cout << fibs[n].first << " " << fibs[n].second << "\n";
    }
}