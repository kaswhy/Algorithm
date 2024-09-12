/*
 * 입력: 두 개의 영어 단어 (소문자, 1 <= len <= 1000)
 * 출력: 두 단어가 서로 애너그램 관계에 있도록 하기 위해 제거해야 하는 최소 문자 수
 *  [조건]
 *  - 두 단어가 순서를 바꿔서 같아질 수 있으면 애너그램 관계
 *  => 알파벳 수가 같아야 함
 *
 *  [문제 풀이]
 *  1. string fst, snd 입력받음
 *  2. 각각 길이만큼 배열을 돌면서 알파벳 배열 2개 만든 거에 개수 셈 (->2000번)
 *  3. 0~26까지 알파벳 배열 돌면서 개수가 다르면 그 차만큼 cnt에 더함
 *
 */
#include <bits/stdc++.h>
using namespace std;

int fst_cnt[26];
int snd_cnt[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string fst, snd;

    cin >> fst;
    for(char c : fst){
        fst_cnt[c-'a']++;
    }

    cin >> snd;
    for(char c: snd){
        snd_cnt[c-'a']++;
    }

    int cnt = 0;
    for(int i = 0; i<26; i++){
        if(fst_cnt[i] != snd_cnt[i]){
            cnt += abs(fst_cnt[i] - snd_cnt[i]);
        }
    }

    cout << cnt;
}