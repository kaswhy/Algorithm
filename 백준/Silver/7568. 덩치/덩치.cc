#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    /*
     * 입력: 전체 사람 수 N / 몸무게 x, 키 y
     * 출력: 덩치 등수
     * 1. pair<pair<int, int>, int> 형태로 입력받기
     * 2. 정렬 (greater<>())
     *  - 이중 포문을 돈다.
     *      - 바깥 포문: 사람 한명씩 등수 계산
     *      - 몸무게 큰 순서대로 정렬되어있으므로,
     *      - 안쪽 포문: 내 앞 사람까지 몸무게 & 키 나랑 비교
     *          -> 나보다 둘다 큰 사람들의 수를 센다
     *          -> 그 수 + 1 한 값을 등수 배열에 저장
     */
    int n, x, y;
    cin >> n;

    vector<pair<pair<int, int>, int>> people;
    vector<int> rank(n);

    for(int i = 0; i <n; i++){
        cin >> x >> y;
        people.push_back({{x, y}, i});
    }

    sort(people.begin(), people.end(), greater<>());

    for(int i = 0; i<n; i++){
        int weight = people[i].first.first;
        int height = people[i].first.second;
        int person = people[i].second;
        int count = 1;

        for(int j = 0; j < i; j++){
            int comp_weight = people[j].first.first;
            int comp_height = people[j].first.second;

            if(comp_weight > weight && comp_height > height){
                count ++;
            }
        }
        rank[person] = count;
    }

    for(int i = 0; i<n; i++){
        cout << rank[i] << " ";
    }
}