#include <bits/stdc++.h>
using namespace std;

int cnt1[26];
int cnt2[26];
int main() {
    int t;
    cin >> t;
    while(t--){
        string fst, snd;
        cin >> fst >> snd;

        fill(cnt1, cnt1+26, 0);
        fill(cnt2, cnt2+26, 0);

        if (fst.size() != snd.size() ){
            cout << "Impossible\n";
            continue;
        }

        for(int i = 0; i<fst.size(); i++){
            cnt1[fst[i]-'a']++;
            cnt2[snd[i]-'a']++;
        }

        int chk = 1;
        for(int i =0; i<26; i++){
            if(cnt1[i] != cnt2[i]){
                chk = 0;
                cout << "Impossible\n";
                break;
            }
        }
        if (chk) cout << "Possible\n";

    }
}