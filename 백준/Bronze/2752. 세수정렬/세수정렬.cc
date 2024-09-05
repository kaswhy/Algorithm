/*
 * 입력: 정수 세 개
 * 출력: 오름차순 정렬 결과
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    cout << nums[0] << " " <<  nums[1] <<  " " << nums[2];
}
