#include <iostream>
using namespace std;

long long v[101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<10; i++) {
        v[1][i] = 1;
    }
    v[1][0] = 0;

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j<10; j++){
            if(j == 0){
                v[i][j] = v[i-1][j+1]; // 0으로 끝나는 수를 만들 수 있는 건 바로 이전 자리 수가 1로 끝나는 경우
                continue;
            }
            if(j == 9){
                v[i][j] = v[i-1][j-1];
                continue;
            }
            v[i][j] = (v[i-1][j-1] % 1000000000 + v[i-1][j+1]% 1000000000) % 1000000000;
        }
    }

    long long int count = 0;
    for(int i = 0; i<10; i++){
        count = (count % 1000000000 + v[n][i] % 1000000000) % 1000000000;
    }

    cout << count;

}