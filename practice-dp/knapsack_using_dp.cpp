#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];
int knapsack(int i, int mx_weight)
{

    // base cases
    if (i < 0 || mx_weight <= 0)
    {
        return 0;
    }

    if (dp[i][mx_weight] != -1)
    {
        return dp[i][mx_weight];
    }

    if (weight[i] <= mx_weight)
    {

        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}

int main()
{

    int n, max_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cin >> max_weight;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_weight; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = knapsack(n - 1, max_weight);
    cout << ans << endl;

    return 0;
}