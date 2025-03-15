// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long n, q;
//     cin >> n >> q;
//     vector<long long> a;
    

//     int i = 1;
//     while (a.size() < n) {
//         a.push_back(i);
//         a.push_back(i);
//         a.push_back(i);
//         i++;
//     }
//     vector<long long> prefix_sum(n + 1, 0);
//     for (int i = 1; i <= n; ++i) {
//         prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
//     }
//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         long long sum = prefix_sum[r] - prefix_sum[l - 1];
//         cout << sum << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;
    
    vector<long long> a;
    for (int i = 1; i <= n / 3; i++) {
        a.push_back(i);
        a.push_back(i);
        a.push_back(i);
    }
    
    vector<long long> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        long long sum = prefix_sum[r] - prefix_sum[l - 1];
        cout << sum << endl;
    }

    return 0;
}
