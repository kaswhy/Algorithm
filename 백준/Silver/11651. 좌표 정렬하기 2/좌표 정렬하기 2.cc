#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    /*
     * 입력: 점의 개수 n / x, y
     * 출력: 점을 정렬한 결과
     *
     */
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for(int i =0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }

    sort(v.begin(), v.end());

    for(int i =0; i<n; i++){
        cout << v[i].second << " " << v[i].first <<"\n";
    }
}