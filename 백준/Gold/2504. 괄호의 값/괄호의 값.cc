/*
 * 입력: 괄호열을 나타내느 문자열 (1 <= size <= 30)
 * 출력: 해당 괄호열이 나타내는 정수
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<string> inf;
    int tmp = 0, cnt = 0;

    for(char c: s){
        if(c=='('){
            inf.push("(");
            continue;
        }
        if(c=='['){
            inf.push("[");
            continue;
        }
        if(c==')'){
            if(inf.empty()){
                tmp =1;
                break;
            }
            if(inf.top() == "("){
                inf.pop();
                inf.push(to_string(2));
                continue;
            }
            int now = 0;
            while(!inf.empty()){
                if(inf.top() == "[" || inf.top() == "]"){
                    break;
                }
                if(inf.top() == "("){
                    break;
                }
                now += stoi(inf.top());
                inf.pop();
            }
            if(inf.empty()){
                tmp = 1;
                break;
            }
            if(inf.top() != "("){
                tmp = 1;
                break;
            }
            now *= 2;
            inf.pop();
            inf.push(to_string(now));
            continue;
        }
        if(c==']'){
            if(inf.empty()){
                tmp =1;
                break;
            }
            if(inf.top() == "["){
                inf.pop();
                inf.push(to_string(3));
                continue;
            }
            int now = 0;
            while(!inf.empty()){
                if(inf.top() == "(" || inf.top() == ")"){
                    break;
                }
                if(inf.top()== "["){
                    break;
                }
                now += stoi(inf.top());
                inf.pop();
            }
            if(inf.empty()){
                tmp = 1;
                break;
            }
            if(inf.top() != "["){
                tmp = 1;
                break;
            }
            now *= 3;
            inf.pop();
            inf.push(to_string(now));
            continue;
        }
    }
    while (!tmp && !inf.empty()) {
        if(inf.top() == "(" || inf.top() == "[" || inf.top() ==")" || inf.top() == "]"){
            tmp = 1;
            break;
        }
        cnt += stoi(inf.top());
        inf.pop();
    }
    if(tmp){
        cout << 0;
    }
    else
        cout << cnt;
}