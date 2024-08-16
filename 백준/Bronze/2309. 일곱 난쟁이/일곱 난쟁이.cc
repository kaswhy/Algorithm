#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    /*
     * 입력: 아홉 명의 키
     * 출력: 일곱 난쟁이 키를 오름차순으로
     * 1. 쭉 입력받으면서 전체 합 구하기
     * 2. 2명에 대한 합을 구하면서 그 합이 차일 경우 출력
     */
    vector<int> people(10, 0);

    int cnt = 0, dif = 0;
    for(int i = 1; i<=9; i++){
        int x;
        cin >> x;
        cnt += x;
        people[i] = x;
    }
    dif = cnt -100;

    int first = 0, second = 0;
    for(int i = 1; i<=9; i++){
        for(int j = i+1; j<=9; j++){
            int tmp = people[i] + people[j];
            if(tmp == dif){
                first = i;
                second = j;
                break;
            }
        }
    }
    
    vector<int> shorts;
    for(int i = 1; i<=9; i++){
        if(i == first || i == second){
            continue;
        }
        shorts.push_back(people[i]);
    }
    
    sort(shorts.begin(), shorts.end());
    
    for(int i =0 ; i<7; i++){
        cout << shorts[i] << "\n";
    }
}