#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //
    sort(a.begin(), a.end(), greater<int>());
    
    int totalBalls = 0;
    int lastTaken = -1;
    for(int i = 0; i < n; i++) {
        if (i == 0 || a[i] < a[i-1]) {
            totalBalls += a[i];
            lastTaken = a[i];
        } 
        else if(a[i] - 1 > 0){
            totalBalls+= a[i]-1;
        }
    }
    
    cout << totalBalls << endl;
    return 0;
}