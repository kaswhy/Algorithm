#include <bits/stdc++.h>
using namespace std;

int arr[5000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;

    int x;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    deque<pair<int, int>> tmp;
    for(int i = 0; i<n; i++){
        if(!tmp.empty() && tmp.front().second + l == i) {
            tmp.pop_front();
        }
        while(!tmp.empty() && tmp[tmp.size()-1].first > arr[i]) {
            tmp.pop_back();
        }
        tmp.push_back({arr[i],i});
        cout << tmp.front().first << " ";
    }
}