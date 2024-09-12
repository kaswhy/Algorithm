/*
 * 입력: 초기 문자열 / 명령어 개수 / 명령어
 * 출력: 모든 명령어 수행 후 남아있는 문자열
 *  [조건]
 *  - 처음 커서 위치는 문장의 맨 뒤
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    int m;
    cin >> m;

    list<char> ans;
    for(char i : s){
        ans.push_back(i);
    }

    auto cursor = ans.end();
    while(m--){
        char c;
        cin >> c;

        if (c == 'L'){
            if (cursor == ans.begin()) continue;
            cursor--;
            continue;
        }
        if (c == 'D'){
            if (cursor == ans.end()) continue;
            cursor++;
            continue;
        }
        if(c == 'B'){
            if (cursor == ans.begin()) continue;
            cursor--;
            cursor = ans.erase(cursor);
            continue;
        }
        if(c=='P'){
            char now;
            cin >> now;
            ans.insert(cursor, now);
            continue;
        }
    }

    for (auto c : ans) cout << c;
}