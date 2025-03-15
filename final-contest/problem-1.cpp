#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> prefix_arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_arr[i] = prefix_arr[i - 1] + a[i]; 
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (prefix_arr[r] - prefix_arr[l - 1]) << endl;
    }

    return 0;
}
