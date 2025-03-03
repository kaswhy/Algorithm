#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;

void print() {
    for(int i = 0; i<N; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void choice(int n) {
    if(n == N + 1) {
        print();
        return;
    }
    
    for(int i = 1; i<=K; i++) {
        answer.push_back(i);
        choice(n+1);
        answer.pop_back();
    }
}

int main() {
    cin >> K >> N;

    choice(1);

    return 0;
}
