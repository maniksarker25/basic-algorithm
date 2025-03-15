#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string newString;

        for (int i = 0; i < s.length(); i += 2) {
            char ch = s[i];           
            int num = s[i + 1] - '0'; 
            newString.append(num, ch);
        }

        cout << newString << endl; 
    }

    return 0;
}
