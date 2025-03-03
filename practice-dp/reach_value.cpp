#include <bits/stdc++.h>
using namespace std;

bool reach(long long currentValue, long long desValue)
{
    if (currentValue == desValue)
    {
        return true;
    }
    if (currentValue > desValue)
    {
        return false;
    }
    return reach(currentValue * 10,desValue) || reach(currentValue * 20,desValue);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
      if(reach(1,n)){
        cout << "YES" << endl;
      }
      else{
        cout << "NO"<<endl;
      }
    }

    return 0;
}