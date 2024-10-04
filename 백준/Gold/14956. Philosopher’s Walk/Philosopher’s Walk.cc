#include <bits/stdc++.h>
using namespace std;

pair<int, int> func (int n, int x){
    if(n == 2){
        switch(x){
            case 1:
                return {1, 1};
            case 2:
                return {1, 2};
            case 3:
                return {2, 2};
            case 4:
                return {2, 1};
        }
    }
    int half = n/2;
    int section = half*half;
    if(x <= section){
        pair<int, int> rv = func(half, x);
        return {rv.second, rv.first};
    }
    else if(x <= 2 * section){
        pair<int, int> rv = func(half, x - section);
        return {rv.first, half+rv.second};
    }
    else if(x <= 3*section){
        pair<int, int> rv = func(half, x - 2*section);
        return {half+rv.first, half+rv.second};
    }
    else {
        pair<int, int> rv = func(half, x -3*section);
        return {2*half - rv.second + 1, half - rv.first + 1};
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    pair<int, int> ans = func(n, m);
    cout << ans.first << " " << ans.second;
}