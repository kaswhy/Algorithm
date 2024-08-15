#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 선수의 수 N / 각 선수의 성
     * 출력: 선수 5명을 선발할 수 없는 경우 PREDAJA / 가능한 성의 첫 글자 모두
     * 1. a ~ z 까지의 배열 만들기
     * 2. 선수 이름 입력받아서 제일 첫글자 +1
     * 3. a ~ z 까지 돌면서 5개 이상인지 아닌지 확인하고 결과 출력
     */
    int n;
    cin >> n;

    vector<int> first(26,0);

    for(int i = 0; i<n; i++){
        string name;
        cin >> name;
        first[name[0]-'a']++;
    }

    int chk = 0;
    for(int i = 0; i<26; i++){
        if(first[i] >= 5) {
            chk = 1;
            cout << char('a' + i);
            continue;
        }
    }

    if(chk == 0){
        cout << "PREDAJA";
    }
}