/*
 * 입력: 단어 수 N / A, B로만 이루어진 문자열
 * 출력: 괄호 쌍의 수
 * 스택 괄호쌍으로 해결
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    while(n--){
        string s;
        cin >> s;

        stack<char> word;
        for(char c : s){
            if(word.empty()){
                word.push(c);
                continue;
            }
            if(word.top() == c){
                word.pop();
                continue;
            }
            word.push(c);
        }

        if(word.empty()){
            cnt++;
        }
    }

    cout << cnt;
}