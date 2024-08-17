#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(101);
vector<bool> check(101, false);
int cnt = 0;

void dfs(int n){
    if(v[n].empty()){
        return;
    }
    check[n] = true;
    for (int i = 0; i < v[n].size(); i++) {
        if(check[v[n][i]]) continue;
        cnt++;
        dfs(v[n][i]);
    }
    return;
}

int main() {
    /*
     * 입력 : 컴퓨터 수 / 연결된 컴퓨터 쌍의 수 / 연결 정보
     * 출력 : 1번 컴퓨터와 연결된 컴퓨터 수
     * 1. 인접 리스트 방식으로 입력 받음
     * 2. 체크할 배열 만들어서 타고 들어가는 방식으로
     *  - 만약에 1이라고 가정하면,
     *      1) v[1] size만큼 돎
     *      2) 관련 노드에 들어가서 또 돎
     */
    int com_num, com_edge;
    cin >> com_num;
    cin >> com_edge;

    for(int i = 0 ; i <com_edge; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    cout << cnt;
}