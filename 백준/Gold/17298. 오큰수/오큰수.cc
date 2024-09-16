/*
 * 입력: 수열의 크기 N / 원소
 * 출력: 각 원소에 대해 오른쪽에 있으면서 해당 수보다 큰 수 중 가장 왼쪽에 있는 수
 * 1. s에 push
 * 2. 오큰수 배열은 n만큼 -1로 초기화
 * 3. tmp 에 s의 top을 push, s pop
 * 4. top끼리 비교
 *  - tmp가 비어있을 때까지 tmp.top() < s.top() 비교
 *      +) t -> tmp.pop()
 *      +) f -> tmp.top()으로 업데이트, t에 s.top() push
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    stack<int> tmp;
    vector<int> nge(n, -1);
    vector<int> v;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int i = n-2;
    tmp.push(v[n-1]);
    while(i >= 0){
        while(!tmp.empty()){
            if(v[i] < tmp.top()){
                nge[i] = tmp.top();
                break;
            }
            tmp.pop();
        }
        tmp.push(v[i]);
        i--;
    }

    for(int x : nge){
        cout << x << " ";
    }
}