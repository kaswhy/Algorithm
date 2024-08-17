#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: n (1 <= n <= 1000)
     * 출력: 2*n 크긱의 직사각형을 채우는 방법의 수 % 10,007
     * 1 -> 1 (세로 1)
     * 2 -> 2 (가로 1, 세로 1)
     * 3 -> 3
     * => v[n] = v[n-1] + v[n-2]
     */
    vector<int> v(1001, 0);
    v[1] = 1, v[2] = 2;
    for(int i = 3; i<=1000; i++){
        v[i] = (v[i-1] % 10007 + v[i-2] % 10007) % 10007;
    }

    int n;
    cin >> n;
    cout << v[n];
}