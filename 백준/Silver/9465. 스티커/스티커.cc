#include <iostream>

using namespace std;
#define MAX 100001

int T, N;
int sticker[2][MAX], dp[2][MAX];

int main() {
    cin >> T;

    while(T--) {
        cin >> N;

        //스티커 첫번째 줄, 두번째 줄 입력 받기
        for(int i=0;i<N;i++)
            cin >> sticker[0][i];
        for(int i=0;i<N;i++)
            cin >> sticker[1][i];
        //초기값 세팅
        for(int i=0;i<2;i++) 
            dp[i][0]=sticker[i][0];
        //초기값 세팅
        dp[0][1] = sticker[0][1]+dp[1][0];
        dp[1][1] = sticker[1][1]+dp[0][0];
    
        //2부터 시작하는 dp 점화식
        for(int i=2;i<N;i++) {
            dp[0][i]=sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i]=sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        //둘 중에 더 큰 값 출력
        cout << max(dp[0][N-1], dp[1][N-1]) << "\n";
    }
}