#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    /*
     * 입력: 수의 개수 N (< 500,000) / 정수 (-4000 <=n <= 4000)
     * 출력:
     * - 산술평균 -> 입력받을 때마다 더함
     * - 중앙값 -> 정렬 후 floor(n/2)번째 값
     * - 최빈값 -> 8000개짜리 배열 만들고 개수 세기
     * - 범위 -> 정렬 후 n-1번째 - 0번째
     */
    int n, x, sum = 0;
    cin >> n;

    vector<int> nums;
    vector<int> cnt(8001, 0);

    for(int i = 0; i<n; i++){
        cin >> x;

        sum += x; // 산술평균 구하기 위해 계속 더함
        nums.push_back(x); // 중앙값, 범위 구하려고
        cnt[x+4000]++; // 해당 수가 나온 빈도를 계속 추적
    }

    double avg = ((double) sum) / n;
    if(round(avg) == 0)
        cout << 0 << "\n";
    else cout << round(avg) << "\n";

    std::sort(nums.begin(), nums.end());
    cout << nums[(n-1) / 2] << "\n"; // 중앙값 출력

    int max_cnt = *max_element(cnt.begin(), cnt.end());
    int first = -4001, second = -4001;
    for(int i = 0; i<8001; i++){
        if(cnt[i] == max_cnt){
            if(first == -4001){
                first = i - 4000;
            }
            else if (second == -4001){
                second = i - 4000;
                break;
            }
        }
    }

    if(second == -4001) cout << first << '\n';
    else cout << second << "\n";

    cout << nums[n-1] - nums[0] << "\n"; // 범위 출력


}