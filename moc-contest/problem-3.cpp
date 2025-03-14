// #include <bits/stdc++.h>
// using namespace std;


// map<int,bool>dp;

// bool isPosible(int val,int target){
//     if(val == target){
//         return true;
//     }
//     if(val > target){
//         return false;
//     }

//     if(dp.cout(val)){
//         return dp[val];
//     }

//     bool result = isPosible(val + 3,target) || isPosible(val + 4,target);
//     dp[val] = result;
//     return result;
// }


// int main()
// {
//     int t;
//     cin >>t;
//     if(isPosible(0,t))
//     {
//     cout << "YES" <<endl;
//     }
//     else{
//         cout << "NO"<<endl;
//     }
    
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// bool isPossible(int target) {
//     vector<bool> dp(target + 1, false);
//     dp[0] = true;

//     for (int i = 0; i <= target; i++) {
//         if (dp[i]) {
//             if (i + 3 <= target) {
//                 dp[i + 3] = true;
//             }
//             if (i + 4 <= target) {
//                 dp[i + 4] = true;
//             }
//         }
//     }

//     return dp[target];
// }

// int main() {
//     int t;
//     cin >> t;
    
//     if (isPossible(t)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    if(t == 3)
        cout << "YES";
    else if(t == 4)
        cout << "YES";
    else if (t >= 6)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}