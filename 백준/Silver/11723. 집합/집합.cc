#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력 : 수행해야 하는 연산 수 M / 수행해야 하는 연산 수
     *  - add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
     *  - remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
     *  - check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
     *  - toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
     *  - all: S를 {1, 2, ..., 20} 으로 바꾼다.
     *  - empty: S를 공집합으로 바꾼다.
     * 출력: check 연산 시의 결과
     */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m;
    cin >> m;

    vector<int> s(21, 0);
    vector<int> tmp(21, 0);
    vector<int> all(21, 1);

    while(m--){
        string command;
        cin >> command;

        if(command == "add"){
            int x;
            cin >> x;
            s[x] = 1;
        }
        if(command == "remove"){
            int x;
            cin >> x;
            s[x] = 0;
        }
        if(command == "check"){ // 출력 필요!
            int x;
            cin >> x;
            cout << s[x] << "\n";
        }
        if(command == "toggle"){
            int x;
            cin >> x;
            if(s[x] == 0){
                s[x] = 1;
                continue;
            }
            s[x] = 0;
        }
        if(command == "all"){
            s = all;
        }
        if(command == "empty"){
            s = tmp;
        }
    }
}