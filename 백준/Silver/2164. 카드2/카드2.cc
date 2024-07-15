#include <iostream>
#include <list>
using namespace std;

int main() {
    /*
     * 입력: n
     * 출력: 첫째 줄에 남는 카드 번호
     *  위에서부터 아래로 1~N까지의 카드가 놓여져있음
     *  1. 1~n까지 리스트 초기화
     *  2. 아래 과정 반복
     *      - 앞에 거 삭제
     *      - 맨앞에 있는 거 임시 저장 & 삭제 후 뒤에 추가
     *      - 벡터의 원소 개수가 1개일 때까지
     *  3. 제일 첫번째 원소 반환
     */
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    list<int> v;
    for(int i = 0; i<n; i++){
        v.push_back(i+1);
    }

    while(v.size() != 1){
        v.pop_front();
        int tmp = v.front();
        v.pop_front();
        v.push_back(tmp);
    }

    cout << v.front();
}