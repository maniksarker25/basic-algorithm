#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[11][11], dp[11][11];

int maximum_sum(int i, int j)
{
    if (i == n && j == m)
    {
        dp[i][j] = a[i][j];
        return dp[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int right = 0, down = 0;

    if (j < m)
        right = maximum_sum(i, j + 1);

    if (i < n)
        down = maximum_sum(i + 1, j);

    dp[i][j] = a[i][j] + max(right, down);

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

    int ans = maximum_sum(1, 1);

    cout << ans << endl;

    return 0;
}