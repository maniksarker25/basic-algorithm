// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >>t;
//     while(t--){
//     int n;
//     cin >>n;
//     vector<int>a(n-2);
//     int sumAfterDelete = 0;
//     for(int i = 0;i<n-2;i++){
//         cin >>a[i];
//         sumAfterDelete+= a[i];
//     }
//     long long sum ;
//     cin >>sum;
//     long long difference = sum - sumAfterDelete;
//     cout << difference +1 <<endl;
//     }
//     return 0;
// }   



#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        long long current_sum = 0;
        for(int i=0; i<n-2; i++){
            cin >> a[i];
            current_sum += a[i];
        }
        long long sum;
        cin >> sum;
        long long difference = sum - current_sum;
        cout << difference + 1 << endl; 
    }
    return 0;
}