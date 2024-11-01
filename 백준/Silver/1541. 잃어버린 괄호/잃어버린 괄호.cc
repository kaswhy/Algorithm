#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    stack<string> exp;

    string tmp = "";
    for(int i = 0; i<s.size(); i++) {
        if (s[i] == '+' || s[i] == '-'){
            exp.push(tmp);
            exp.push(s.substr(i,1));
            tmp="";
            continue;
        }
        tmp += s[i];
    }
    exp.push(tmp);

    int sum = 0, tmpint = 0;
    while(!exp.empty()) {
        string now = exp.top();
        exp.pop();
        if(now == "+") {
            continue;
        }
        if(now == "-") {
            sum -= tmpint;
            tmpint = 0;
            continue;
        }
        tmpint += stoi(now);
    }
    sum += tmpint;

    cout << sum;

}