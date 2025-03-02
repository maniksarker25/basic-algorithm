#include<bits/stdc++.h>
using namespace std; // O(n)
int dp[1005];

int fibo(int n)
{
   if(n == 0 || n==1){
    return n;
   }
    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}

int main(){
    memset(dp,-1,sizeof(dp));
    cout << fibo(9) << endl;
    return 0;
}