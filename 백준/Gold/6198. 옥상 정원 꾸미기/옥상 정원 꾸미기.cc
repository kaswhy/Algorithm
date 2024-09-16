/*
 * 입력: 빌딩 수 N / 각 빌딩의 높이 h
 * 출력: 각 관리인들이 볼 수 있는 빌딩 수의 합
 *  1. 입력받은 순서대로 배열에 넣기 (push_back)
 *  2. 포인터 2개를 가지고 움직이면서 개수 세기
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long int n;
    cin >> n;

    vector<long long int> build;
    for(long long int i = 0; i<n; i++){
        int x;
        cin >> x;
        build.push_back(x);
    }

    long long int i = n-2, j = n-1, cnt = 0;
    while(i >= 0){
        while(j <= n-1){
            if(build[i] > build[j]){
                cnt++;
                j++;
                continue;
            }
            break;
        }
        i--;
        j = i+1;
    }

    cout << cnt;
}