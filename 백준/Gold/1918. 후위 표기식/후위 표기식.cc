#include <iostream>
#include <stack>
using namespace std;

// 연산자 우선순위 반환
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    string s;
    cin >> s;

    stack<char> operations;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            operations.push('(');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (!operations.empty() && precedence(operations.top()) >= precedence(s[i])) {
                cout << operations.top();
                operations.pop();
            }
            operations.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!operations.empty() && operations.top() != '(') {
                cout << operations.top();
                operations.pop();
            }
            if (!operations.empty() && operations.top() == '(') {
                operations.pop(); // 여는 괄호 제거
            }
        }
    }

    // 스택에 남은 모든 연산자 출력
    while (!operations.empty()) {
        cout << operations.top();
        operations.pop();
    }

    cout << endl;
    return 0;
}
