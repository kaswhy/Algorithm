/*
 * 입력: 테스트 케이스 t / 함수 p / 배열 크기 N / 배열에 있는 정수
 * 출력: 함수 수행 결과
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string com;
        cin >> com;

        int n;
        cin >> n;

        string arr, tmp="";
        cin >> arr;

        deque<int> d;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i]==',' || arr[i]==']'){
                if(tmp == "") break;
                d.push_back(stoi(tmp));
                tmp="";
                continue;
            }
            tmp += arr[i];
        }

        bool reverse = false;
        bool error = false;
        for(char c : com){
            if(c == 'R'){
                if(!reverse){
                    reverse = true;
                    continue;
                }
                reverse = false;
                continue;
            }
            if(c == 'D'){
                if(d.empty()){
                    error = true;
                    break;
                }
                if(reverse){
                    d.pop_back();
                    continue;
                }
                d.pop_front();
                continue;
            }
        }

        if(error){
            cout << "error\n";
            continue;
        }
        if(reverse) {
            cout << "[";
            while(!d.empty()){
                if(d.size() > 1) {
                    cout << d.back() << ",";
                    d.pop_back();
                    continue;
                }
                cout << d.back();
                d.pop_back();
            }
            cout << "]\n";
            continue;
        }
        cout << "[";
        while(!d.empty()){
            if(d.size() > 1)  {
                cout << d.front() << ",";
                d.pop_front();
                continue;
            }
            cout << d.front() ;
            d.pop_front();
        }
        cout << "]\n";
    }
}