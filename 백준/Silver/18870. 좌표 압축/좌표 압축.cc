#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    /*
     * 입력: N / 공백 한 칸으로 구분된 X1, X2, ..., Xn
     * 출력: 좌표 압축한 결과를 한 줄로
     * 입력 받고 -> 정렬 하고 -> lower_bound 이용해서 각각 찾고
     */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> origin; // 정렬 x
    vector<int> nums; // 정렬
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        origin.push_back(x);
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // vector 내 중복된 원소 제거

    for(int i = 0; i < n; i++){
        int now = origin[i];
        cout << distance(nums.begin(), lower_bound(nums.begin(), nums.end(), now)) << " ";
    }
}