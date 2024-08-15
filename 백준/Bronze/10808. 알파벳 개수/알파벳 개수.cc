#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 단어 s
     * 출력: a ~ z 까지 각각 몇 개인지 공백으로 구분하여 출력
     * 1. 입력받음
     * 2. 한 글자씩 <해당 글자 - 'a'>번째 ++;
     * 3. 출력
     */
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for(int i = 0; i<s.size(); i++){
        cnt[s[i]-'a']++;
    }

    for(int i = 0; i<26; i++){
        cout << cnt[i] << " ";
    }
}