#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> deq;

    while(n--){
        int order;
        cin >> order;

        switch(order) {
            case 1:
                int x;
                cin >> x;
                deq.push_front(x);
                break;
            case 2:
                int y;
                cin >> y;
                deq.push_back(y);
                break;
            case 3:
                if(deq.empty()) {
                    cout << -1 << "\n";
                    break;
                }
                cout << deq.front() << "\n";
                deq.pop_front();
                break;
            case 4:
                if(deq.empty()) {
                    cout << -1 << "\n";
                    break;
                }
                cout << deq.back() << "\n";
                deq.pop_back();
                break;
            case 5:
                cout << deq.size() << "\n";
                break;
            case 6:
                if(deq.empty()){
                    cout << 1 << "\n";
                    break;
                }
                cout << 0 << "\n";
                break;
            case 7:
                if(deq.empty()) {
                    cout << -1 << "\n";
                    break;
                }
                cout << deq.front() << "\n";
                break;
            case 8:
                if(deq.empty()) {
                    cout << -1 << "\n";
                    break;
                }
                cout << deq.back() << "\n";
                break;
        }
    }
}