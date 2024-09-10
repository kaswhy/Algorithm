#include <bits/stdc++.h>
using namespace std;

int student[6][2];
int main() {
    int n, t;
    cin >> n >> t;

    for(int i = 0; i<n; i++){
        int s, y;
        cin >> s >> y;
        student[y-1][s]++;
    }

    int cnt = 0;
    for(auto & i : student){
        for(int j : i){
            if(j == 0){
                continue;
            }
            if(j % t == 0){
                cnt += j / t;
                continue;
            }
            cnt += (j / t + 1);
        }
    }

    cout << cnt;
}