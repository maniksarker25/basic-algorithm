#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int totalBalls = 0;
    int lastTaken = -1;

    for(int i = 0; i < n; i++) {
        if (a[i] <= lastTaken) {
            if (lastTaken > 0) {
                
                lastTaken--;
                totalBalls += lastTaken;
            }
        } else {
            lastTaken = a[i];
            totalBalls += lastTaken;
        }
    }

    cout << totalBalls << endl;
    return 0;
}
