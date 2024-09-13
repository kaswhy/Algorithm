/*
 * 입력: 테스트케이스 / 입력한 문자열
 * 출력: 비밀번호
 *  [조건]
 *  - 백스페이스: '-'
 *  - 화살표 : '<' , '>'
 *  BAPC
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        list<char> pw;
        auto cursor = pw.begin();

        for(char c: s){
            if(c=='<'){
                if(cursor != pw.begin()){
                    cursor--;
                }
                continue;
            }
            if(c=='>'){
                if(cursor != pw.end()){
                    cursor++;
                }
                continue;
            }
            if(c=='-'){
                if(!pw.empty() && cursor != pw.begin()){
                    cursor--;
                    cursor = pw.erase(cursor);
                }
                continue;
            }
            pw.insert(cursor, c);
            
        }

        for (char c  : pw){
            cout << c;
        }
        cout << "\n";
    }
}