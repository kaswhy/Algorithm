#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     *  입력: 참가자 수 N, 티셔츠 사이즈별 신청자 수, 티셔츠와 펜 한 묶음 당 개수
     *  출력: 최소 주문해야 하는 티셔츠 묶음 수 T/ P자루씩 최대 몇 묶음 주문 가능한지, 펜을 한 자루씩 몇 개 주문하는지
     *  참가자들에게 "티셔츠 하나, 펜 하나" 를 주려고 함
     *  이때 키트 제작 업체 주문 조건
     *  1. 티셔츠 사이즈 - S, M, L, XL, XXL, XXXL (6가지), 같은 사이즈 T장 묶음으로만 주문 가능 -> 남아도 됨
     *  2. 펜 - 한 종류, P자루씩 묶음 주문 or 1자루씩 주문 가능 -> 정확해야 함
     *
     *  문제 풀이
     *  1. 티셔츠 - 나머지가 0 일 때는 사이즈 / 묶음 수, 0이 아닐 땐 (사이즈 / 묶음 수) + 1
     *      -> 변수 하나 0으로 초기화 시켜서 위에서 계산한 값을 계속 더하는 방식
     *  2. 펜 - 사람 수 / 묶음 수, 사람 수 % 묶음 수
     */
    int N, T, P, tCount = 0, pAll, pOne;
    vector<int> shirts(6, 0);

    cin >> N;
    for(int i = 0; i<6; i++){
        cin >> shirts[i];
    }
    cin >> T >> P;

    for(int i = 0; i<6; i++) {
        if (shirts[i] % T == 0){
            tCount += (shirts[i] / T);
            continue;
        }
        tCount += (shirts[i] / T + 1);
    }

    pAll = N / P;
    pOne = N % P;

    cout << tCount << "\n";
    cout << pAll << " " << pOne;
}
