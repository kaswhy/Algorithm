/*
 * 입력: 수빈이가 있는 위치 N, 동생 위치 K
 * 출력: 수빈이가 동생을 찾는 가장 빠른 시간
 * => 1차원 BFS (DP?)
 */
#include <bits/stdc++.h>
using namespace std;

int dist[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    fill(dist, dist+100001, -1);

    queue<int> que;
    que.push(n);
    dist[n]++;

    while(!que.empty()){
        int now = que.front(); que.pop();

        if(now == k){
            cout << dist[now];
            return 0;
        }

        int n3 = now * 2;
        if(n3>= 0 && n3 <= 100000){
            if(dist[n3] == -1) {
                dist[n3] = dist[now];
                que.push(n3);
            }
        }

        int n1 = now - 1;
        if(n1>= 0 && n1 <= 100000){
            if(dist[n1] == -1) {
                dist[n1] = dist[now] + 1;
                que.push(n1);
            }
        }

        int n2 = now + 1;
        if(n2>= 0 && n2 <= 100000){
            if(dist[n2] == -1) {
                dist[n2] = dist[now] + 1;
                que.push(n2);
            }
        }
    }
}