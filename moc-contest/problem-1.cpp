#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;i++){
      cin >> a[i].first;
      a[i].second = i;
    }

    sort(a.begin(),a.end());
    int t;
    cin >>t;
    int l = 0;
    int r = n-1;
    int index = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid].first == t){
            index = a[mid].second;
            break;
        }
        else if(a[mid].first > t){
          r = mid -1;

        }
        else{
            l = mid +1;
        }
    }
    cout << index;



    return 0;
}