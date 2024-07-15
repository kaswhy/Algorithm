#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: n, 갖고있는 n개의 카드, m, 알고 싶은 m개의 수
     * 출력: m개의 수에 대해 몇장의 카드를 가지고 있는지
     * 1. map을 쓰자!
     *      - 카드 설정) 1추가
     *      - 검색) 검색해서 있으면 해당 value 리턴, 아니면 0 반환
     */
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, x, m, y;
    map<int, int> cards;

    cin>> n;

    // 가지고 있는 카드 정보 입력
    for(int i = 0; i<n; i++){
        cin >> x;
        cards[x]++;
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> y;
        if(cards.find(y) == cards.end()) {
            cout << 0 << " ";
            continue;
        }
        cout << cards[y] << " ";
    }
}
