#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 첫째 줄 - 정수 k, 둘째 줄 - 정수 n
     * 출력: k층 n호의 거주민 수
     * a층의 b호 : a-1의 1~b까지 사람 수의 합
     * 아파트는 0층부터 있고, 각층은 1호부터 있다.
     */
    vector<vector<int>> apart (15, vector<int> (15));

    for(int i = 0; i<15; i++){
        for(int j = 1; j<15; j++){
            if(i == 0){
                apart[i][j] = j;
                continue;
            }
            int sum = 0;
            for(int k = 1; k<=j; k++){
                sum += apart[i-1][k];
            }
            apart[i][j] = sum;
        }
    }

    int t, k, n;
    cin >> t;

    while(t--){
        cin >> k;
        cin >> n;
        cout << apart[k][n] << "\n";
    }
}