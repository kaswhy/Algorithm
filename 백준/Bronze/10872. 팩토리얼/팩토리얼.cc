#include <iostream>
using namespace std;

long long int factorial(long long int x){
    if(x<=1){
        return 1;
    }
    return x * factorial(x-1);
}

int main() {
    long long int x;
    cin >> x;
    cout << factorial(x);
}