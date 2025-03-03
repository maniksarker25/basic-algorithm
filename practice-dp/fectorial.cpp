#include <bits/stdc++.h>
using namespace std;

long long fec(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fec(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << fec(n) << endl;
    return 0;
}