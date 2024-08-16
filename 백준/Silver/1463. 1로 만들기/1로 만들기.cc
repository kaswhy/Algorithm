#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 1 <= N <= 10^6
     * 출력: 1을 만들기 위한 최소 연산 횟수
     * -> dp
     *  - cnt[1] = 0, cnt[2] = 1, cnt[3] = 1
     *  - 그 이후는 3으로 나눠질 때, 2로 나누어떨어질 때, 1을 뺐을 때
     *    중 가장 최솟값에 1 더한 것으로 결정
     */
    int n;
    cin >> n;

    vector<int> cnt(1000001, 1000000);
    cnt[1] = 0, cnt[2] = 1, cnt[3] = 1;

    for(int i = 4; i<=1000000; i++){
        int min = 1000000;

        int first = (i % 3 == 0)? cnt[i/3]: 1000000;
        if(first < min){
            min = first;
        }

        int second = (i % 2 == 0)? cnt[i/2]: 1000000;
        if(second < min){
            min = second;
        }

        int third = cnt[i-1];
        if(third < min){
            min = third;
        }
        cnt[i] = min + 1;
    }

    cout << cnt[n];
}