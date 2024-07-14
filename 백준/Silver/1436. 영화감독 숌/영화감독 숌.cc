#include <iostream>
using namespace std;

int main() {
    /*
     * 입력: 자연수 n
     * 출력: n번째 종말의 수 (666을 포함하는 수 중 n번째로 작은 수)
     * 666부터 시작해서 하나씩 증가시켜가며 확인
     */
    int n, title, check = 0;

    cin >> n;

    for(title = 666; ; title++){
        string s = to_string(title);
        if(s.find("666") != -1){
            check++;
        }
        if(check == n){
            cout << s;
            break;
        }
    }
}