#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
pair<int, int> seg[15];
int max_cnt = 0;
vector<pair<int, int>> selected;

bool isOverlap(pair<int, int> a, pair<int, int> b) {
    // 끝점도 겹침으로 판단
    return !(a.second < b.first || b.second < a.first);
}

void backtrack(int idx, int count) {
    if (idx == n) {
        max_cnt = max(max_cnt, count);
        return;
    }

    // 현재 선분을 선택하는 경우
    bool canSelect = true;
    for (auto& s : selected) {
        if (isOverlap(s, seg[idx])) {
            canSelect = false;
            break;
        }
    }

    if (canSelect) {
        selected.push_back(seg[idx]);
        backtrack(idx + 1, count + 1);
        selected.pop_back(); // 원상복구
    }

    // 선택하지 않는 경우
    backtrack(idx + 1, count);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    backtrack(0, 0);

    cout << max_cnt << endl;
    return 0;
}
