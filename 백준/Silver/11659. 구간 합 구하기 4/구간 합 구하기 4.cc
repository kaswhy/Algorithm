#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * 입력: 수의 개수 n, 합 구하는 횟수 m / n개의 수 / 합을 구해야하는 구간 i, j
     * 출력: i번째 수부터 j번째 수까지의 합
     * -> 입력받을 때마다 구간합을 저장함
     * -> v[j] - v[i-1]
     */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, x, a, b;
    cin >> n >> m;

    vector<int> v(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >> x;
        v[i] = v[i-1] + x;
    }

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        cout << v[b] - v[a-1] << "\n";
    }
}