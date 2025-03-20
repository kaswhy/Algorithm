#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[20][20];
int visit[20][20];
int max_size = 0;
int now = 0;
vector<pair<int, int>> v;


void choice(int num) {
    if(num == v.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 폭탄이 떨어진 부분 개수세기
                if(visit[i][j] <= -1) {
                    now++;
                }
            }
        }
        if(now > max_size) max_size = now;
        now = 0;
        return;
    }

    int y = v[num].first;
    int x = v[num].second;

    for(int i = 1; i<=3; i++) {
        // 폭탄 종류 & 범위 맞는지 확인 후 색칠
        visit[y][x]--;
        if(i == 1){
            if(y-2 >= 0) visit[y-2][x]--;
            if(y-1 >= 0 ) visit[y-1][x]--;
            if(y+1 <= n-1) visit[y+1][x]--;
            if(y+2 <= n-1) visit[y+2][x]--;
        }

        if(i == 2) {
            if(y-1 >= 0 ) visit[y-1][x]--;
            if(y+1 <= n-1 ) visit[y+1][x]--;
            if(x-1 >= 0 ) visit[y][x-1]--;
            if(x+1 <= n-1) visit[y][x+1]--;
        }

        if(i == 3) {
            if(x-1 >=0 && y-1 >= 0) visit[y-1][x-1]--;
            if(x+1 <=n-1 && y-1 >= 0 ) visit[y-1][x+1]--;
            if(x+1 <= n-1 && y+1 <= n-1)visit[y+1][x+1]--;
            if(x-1 >=0 && y+1 <= n-1) visit[y+1][x-1]--;
        }

        // 다음 폭탄
        choice(num+1);
        
        // 색칠한 거 비우기
        visit[y][x]++;
        if(i == 1){
            if(y-2 >= 0 ) visit[y-2][x]++;
            if(y-1 >= 0 ) visit[y-1][x]++;
            if(y+1 <= n-1) visit[y+1][x]++;
            if(y+2 <= n-1) visit[y+2][x]++;
        }

        if(i == 2) {
            if(y-1 >= 0 ) visit[y-1][x]++;
            if(y+1 <= n-1 ) visit[y+1][x]++;
            if(x-1 >= 0 ) visit[y][x-1]++;
            if(x+1 <= n-1) visit[y][x+1]++;
        }

        if(i == 3) {
            if(x-1 >= 0 && y-1 >= 0 ) visit[y-1][x-1]++;
            if(x+1 <= n-1 && y-1 >= 0 ) visit[y-1][x+1]++;
            if(x+1 <= n-1 && y+1 <= n-1) visit[y+1][x+1]++;
            if(x-1 >=0 && y+1 <= n-1) visit[y+1][x-1]++;
        }

    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            // 폭탄이면
            if(grid[i][j] == 1) {
                v.push_back({i, j});
            }
        }
    }

    choice(0);

    cout << max_size;

    return 0;
}
