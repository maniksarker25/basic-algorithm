#include<bits/stdc++.h>
using namespace std; // O(2 the power n)


int fibo(int n)
{
   if(n == 0 || n==1){
    return n;
   }
    return fibo(n-1) + fibo(n-2);
}

int main(){
    cout << fibo(9) << endl;
    return 0;
}