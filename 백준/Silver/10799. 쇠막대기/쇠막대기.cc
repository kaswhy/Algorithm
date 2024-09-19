/*
 * 입력: 쇠막대기와 레이저 배치를 나타내는 괄호 표현
 * 출력: 잘려진 조각의 총 개수
 *  [조건]
 *  - 쇠막대기를 아래에서 위로 겹쳐놓고 레이저를 위에서 수직으로 발사하여 자름
 *  - 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓음
 *  - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록
 *  - 각 쇠막대기를 자르는 레이저는 적어도 하나 존재
 *  - 레이저는 어떤 쇠막대기의 양 끝점과도 안 겹침
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 0, tmp = 0;
    for(int i = 0; i<s.size(); i++){
        char c = s[i];
        if(c=='('){
            tmp++;
            continue;
        }
        if(c==')' && s[i-1] == '('){
            tmp--;
            cnt += tmp;
            continue;
        }
        cnt += 1;
        tmp--;
    }

    cout << cnt;
}