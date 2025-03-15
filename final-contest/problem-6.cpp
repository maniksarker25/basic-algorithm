#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long countSubsequences(const string& s, const string& t) {
    int n = s.length();
    int m = t.length();
    
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string t;
        cin >>t;
        
        long long result = countSubsequences(s, t);
        cout << result << endl;
    }
    
    return 0;
}