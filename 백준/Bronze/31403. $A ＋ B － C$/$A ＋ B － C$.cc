#include <iostream>
using namespace std;

int main() {
    /*
     * 입력: int a, b, c
     * 출력: 수로 생각했을 때의 a + b - c / 문자열로 생각했을 때의 a + b - c
     */
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << "\n";

    string a_char = to_string(a);
    string b_char = to_string(b);
    a_char += b_char;

    int new_a = stoi(a_char);
    cout << new_a - c;
}