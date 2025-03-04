#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];

int knapsack(int i, int mx_weight)
{

    // base cases
    if (i < 0 || mx_weight <= 0)
    {
        return 0;
    }

    if (weight[i] <= mx_weight)
    {
        // 2 option
        //  1 . bag a rakbo , 2. bag a rakbo nah
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        return max(opt1, opt2);
    }
    else
    {
        // bag a rakta parbo nah
        return knapsack(i - 1, mx_weight);
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
    int ans = knapsack(n - 1, max_weight);
    cout << ans << endl;

    return 0;
}