/*
 * 입력: 수열 크기 n / 수열에 포함되는 수 / x
 * 출력: 쌍의 개수
 *  [구하는 것]
 *  - ai + aj = x (1 <= i < j <= n)을 만족하는 (ai, aj)의 쌍의 수
 *
 *  [조건]
 *  - 1 <= n <= 100,000
 *  - 1 <= ai <= 1,000,000
 *  - 1 <= x <= 2,000,000
 *
 *  1~1,000,000까지 있는 수열 하나 만들고
 *  x - now 가 있으면 전체 개수 ++, 없으면 now ++
 */
#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];

int main(){
    int n, x;
    cin >> n;

    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        nums[i] = a;
    }

    cin >> x;

    int sum = 0;
    for(int i = 0; i< n; i++){
        if(x > nums[i] && x-nums[i] <= 1000000) {
            if (cnt[x - nums[i]]) {
                sum++;
                continue;
            }
            cnt[nums[i]]++;
        }
    }

    cout << sum;
}