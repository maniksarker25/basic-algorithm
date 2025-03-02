#include <bits/stdc++.h>
using namespace std; // O(n)
int dp[1005];

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    // memoization
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}