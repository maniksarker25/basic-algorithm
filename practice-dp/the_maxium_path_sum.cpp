

#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[11][11], dp[11][11];

long long maximum_sum(int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == n && j == m)
    {
        dp[i][j] = a[i][j];
        return dp[i][j];
    }

    long long right = LLONG_MIN, down = LLONG_MIN;
    if (i < n)
    {
        down = maximum_sum(i + 1, j);
    }
    if (j < m)
    {
        right = maximum_sum(i, j + 1);
    }
    dp[i][j] = max(right, down) + a[i][j];
    return dp[i][j];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    long long ans = maximum_sum(1, 1);
    cout << ans << endl;

    return 0;
}
