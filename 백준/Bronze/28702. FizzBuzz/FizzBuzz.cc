#include <iostream>
#include <string>
using namespace std;

int main() {
    /*
     * 입력: 문자열
     * 출력: i / 문자열
     * i가 3의 배수 && 5의 배수 ) FizzBuzz
     * i가 3의 배수 ) Fizz
     * i가 5의 배수 ) Buzz
     * else ) i
     * => 일단 첫번째 글자가 숫자면 그대로니까 그것만 본다
     *  -> 입력받을 때는 count를 3으로 초기화하고 하나씩 감소시킴
     *  -> 숫자가 나오면 그 숫자에 count만큼 더한 값을 판단 후 출력 & 리턴
     */
    string a, result;

    for(int i = 3; i>=1; i--){
        cin >> a;
        if(a[0] - '0' >= 0 && a[0] - '0' <= 9 ){
            int x = stoi(a);
            x += i;
            if(x % 3 == 0 && x % 5 == 0){
                result = "FizzBuzz";
            }
            else if (x % 3 == 0){
                result = "Fizz";
            }
            else if (x % 5 == 0){
                result = "Buzz";
            }
            else {
                result = to_string(x);
            }
        }
    }
    cout << result;
}