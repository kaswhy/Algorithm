#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    /*
     * 입력: 이미 갖고 있는 랜선 수 K, 필요한 랜선 수 N / 각 랜선 길이
     * 출력: 최대 길이
     * -> 다 더해서 n으로 나눈 것보단 짧을 듯
     *  =>  일단 다 더해서 n으로 나누고
     *      그 결과로 다 나눠서 합한 결과가 10이 되는지 확인
     */
    int k, n;
    cin >> k >> n;

    long long int x, cnt = 0, div;
    vector<long long int> nums;

    for(int i = 0; i<k; i++){
        cin >> x;
        nums.push_back(x);
        cnt += x;
    }

    long long int max = cnt;
    long long int min = 1;

    while(min <= max){
        long long int sum = 0;
        long long int mid = (min + max) / 2;
        for(int i = 0; i<k; i++){
            sum += nums[i] / mid;
        }
        if(sum < n) {
            max = mid - 1;
        }
        else {
            div = mid;
            min = mid + 1;
        }
    }
    cout << div;
}