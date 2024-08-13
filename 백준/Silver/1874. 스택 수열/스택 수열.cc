#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    /*
     * [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop]
     *      1 / 2 / 5 / 7 / 8/
     *      4 / 3 / 6 / 8 / 7/ 5 / 2/ 1
     *
     *      1 / 2 / 5 / 3/ 4
     *
     *  입력 :  n 개의 숫자
     *  출력 : 명령어 순서 or NO
     *  1 ~ n까지의 배열 만들어놓기 -> 십만
     *  큐에 명령어 넣어보기
     */
    int n;
    cin >> n;

    queue<int> nums; // 1 ~ n
    vector<int> inputs; // 특정 수열
    vector<int> making; // 해당 수열 만드는 과정 -> push
    vector<int> result; // 결과 -> pop
    queue<char> commands; // 명령어

    int chk = 1;

    for(int i = 0; i<n; i++){
        nums.push(i+1);

        int k;
        cin >> k;
        inputs.push_back(k);
    }

    for(int i = 0; i<n; i++){
        int now = inputs[i]; // 3
        int comp = making.empty()? 0: making[making.size()-1]; //
        if(comp < now) {
            while (!nums.empty() && nums.front() <= now) {
                making.push_back(nums.front());
                commands.push('+');
                nums.pop();
            }
            result.push_back(making[making.size()-1]);
            making.pop_back();
            commands.push('-');
        }
        else if (comp == now) {
            result.push_back(making[making.size()-1]);
            making.pop_back();
            commands.push('-');
        }
        else {
            chk = 0;
            break;
        }
    }

    if(chk) {
        for (int i = 0; i < n*2; i++) {
            cout << commands.front() << "\n";
            commands.pop();
        }
    }
    else cout << "NO";
}