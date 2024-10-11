#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[15];
char ans[15];
bool isused[15];
int vowel_cnt;
int else_cnt;

void func(int cur, int st){
    if(cur == l && vowel_cnt >= 1 && else_cnt >= 2){
        for (int i = 0; i < l; i++) {
            cout << ans[i];
        }
        cout << '\n';
        return;
    }

    for (int i = st; i < c; i++) {
        if (!isused[i]) {
            if (cur == 0 || (cur > 0 && ans[cur-1] < arr[i])) {
                isused[i] = true;
                switch (arr[i]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        vowel_cnt++;
                        break;
                    default:
                        else_cnt++;
                }
                ans[cur] = arr[i];
                func(cur + 1, st + 1);
                switch (arr[i]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        vowel_cnt--;
                        break;
                    default:
                        else_cnt--;
                }
                isused[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+c);

    func(0, 0);
}