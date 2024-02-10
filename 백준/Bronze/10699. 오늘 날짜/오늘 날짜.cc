#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    cout << 1900 + t -> tm_year << "-";
    cout.width(2);
    cout.fill('0');
    cout << t -> tm_mon + 1 << "-";
    cout.width(2);
    cout.fill('0');
    cout << t -> tm_mday;
}