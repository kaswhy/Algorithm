#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 테스트케이스 t / 정수 n < 11
     * 출력: n을 1, 2, 3의 합으로 나타내는 방법의 수
     * n = 1 -> 1 ( 1 ) +3
     * n = 2 -> 2 ( 1+1, 2) +2
     * n = 3 -> 4 ( 1+1+1, 1+2, 2+1, 3 ) +1
     * n = 4 -> 7 ( 1+1+1+1, 1+2+1, 2+1+1, 3+1, 1+1+2, 2+2, 1+3)
     * => v[n] = v[n-1] + v[n-2] + v[n-3]
     */
    int t, n;
    vector<int> v(11);
    v[1] = 1, v[2] = 2, v[3] = 4;

    for(int i = 4; i<=10; i++){
        v[i] = v[i-1] + v[i-2] + v[i-3];
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << v[n] << "\n";
    }
}