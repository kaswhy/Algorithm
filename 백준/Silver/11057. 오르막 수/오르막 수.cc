#include<iostream>
using namespace std;
int dp[1002][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i < 1002; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int n;
    cin >> n;
    cout << dp[n + 1][9] << endl;
    return 0;
}
