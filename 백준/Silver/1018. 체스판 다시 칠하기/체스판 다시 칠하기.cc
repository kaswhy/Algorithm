#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> makeBlack(int n, int m){
    vector<vector<char>> v (n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((i + j) % 2 == 0) {
                v[i][j] = 'B';
                continue;
            }
            v[i][j] = 'W';
        }
    }
    return v;
}

vector<vector<char>> makeWhite(int n, int m){
    vector<vector<char>> v (n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((i+ j) % 2 == 0) {
                v[i][j] = 'W';
                continue;
            }
            v[i][j] = 'B';
        }
    }
    return v;
}

int main() {
    /*
     * 입력 : n, m, 보드 상태
     * 출력 : 다시 칠해야 하는 정사각형 개수
     * 1. n, m 받아서 보드 2개 2차원 벡터로 미리 만들어 놓음
     *  -> B로 시작하는 거 하나, W로 시작하는 거 하나
     * 2. 입력받아서 한 칸씩 그걸로 비교
     *  - 시작할 수 있는 모든 위치에서
     *  - 하나하나씩 비교해야 함
     *  (아예 밖에서 min = 32로 초기화하고,
     *  계속 카운트 하면서 최종 결과가 min보다 작은 게 있으면 업데이트)
     */
    int n, m;
    cin >> n >> m;

    vector<vector<char>> blackChess = makeBlack(n, m);
    vector<vector<char>> whiteChess = makeWhite(n, m);
    vector<vector<char>> chess (n, vector<char> (m));

    // 입력 받는 부분
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;

        for(int j = 0; j<m; j++){
            chess[i][j] = s[j];
        }
    }

    // 비교하는 부분
    int min = 32; // 8*8이니까 다 바꿔야 하는 건 그 절반인 32가 최댓값
    for(int i = 0; i<=n-8; i++){
        for(int j = 0; j<=m-8; j++) { // 여기까지가 시작 위치 정하는 부분
            // B로 시작하는 거랑 W로 시작하는 거랑 각각 count
            int blackCount = 0, whiteCount = 0;

            for(int x = i; x < i+8; x++){ // 실제 비교부
                for(int y = j; y < j+8; y++){
                    if(blackChess[x][y] != chess[x][y]){
                        blackCount++;
                    }
                    if(whiteChess[x][y] != chess[x][y]){
                        whiteCount++;
                    }
                }
            }

            if(blackCount <= whiteCount){
                if(blackCount < min){
                    min = blackCount;
                }
            }
            else {
                if (whiteCount < min) {
                    min = whiteCount;
                }
            }
        }
    }

    cout << min;

}