#include <bits/stdc++.h>
using namespace std;

int fect(int val)
{
    if (val == 1)
    {
        return 1;
    }
    // int facto = fect(val - 1);
    // return facto * val;
    // sortcut 
    return val * fect(val-1);
}

int main()
{
    cout << fect(5) << endl;
    return 0;
}