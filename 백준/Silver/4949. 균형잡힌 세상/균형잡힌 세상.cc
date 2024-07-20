#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    /*
     * 입력: 문자열
     * 출력: 각 줄이 균형인지의 여부
     * 1. 한줄씩 문자열을 읽으면서 (, [는 스택에 push
     * 2. 닫는 괄호를 만나면
     *      - top에 있는 괄호가 매치되는지 확인 후
     *      -> 매치되지 않으면 그냥
     *      - 해당 문자열 pop
     * 3. 온점을 만나면 스택이 비었는지 아닌지 확인
     */
    string s;

    while(true) {
        getline(cin, s);

        vector<char> c;

        if(s == "."){
            break;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                c.push_back(s[i]);
            } else if (s[i] == ')') {
                if (c.empty()) {
                    cout << "no\n";
                    break;
                }
                if (c[c.size() - 1] == '(') {
                    c.pop_back();
                    continue;
                }
                cout << "no\n";
                break;
            } else if (s[i] == ']') {
                if (c.empty()) {
                    cout << "no\n";
                    break;
                }
                if (c[c.size() - 1] == '[') {
                    c.pop_back();
                    continue;
                }
                cout << "no\n";
                break;
            } else if (s[i] == '.') {
                if (c.empty()) {
                    cout << "yes\n";
                    break;
                }
                cout << "no\n";
            }
        }
    }
}