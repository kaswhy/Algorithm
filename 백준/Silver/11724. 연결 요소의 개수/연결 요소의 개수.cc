#include <iostream>
#include <vector>
using namespace std;
int cc = 0;
vector<vector<int>> graph(1001);
vector<bool> check(1001, false);

void dfs(int x){
    if(check[x] == true) return;
    check[x] = true;
    for(int i = 0; i<graph[x].size(); i++){
        if(check[graph[x][i]] == false){
            dfs(graph[x][i]);
        }
    }
}

int main() {
    /*
     * 입력: 정점 개수 N, 간선 개수 M / 간선 양 끝점 u, v
     * 출력: 연결 요소 개수
     * DFS
     */
    int n, m, u, v;
    cin >> n >> m;

    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i<=n; i++){
        if(check[i] == false) {
            dfs(i);
            cc++;
        }
    }
    cout << cc;
}