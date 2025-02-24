#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            int trial;
            cin >> trial;
            freq[trial]++;
        }

        int result = -1;
        for (auto &pair : freq)
        {
            if (pair.second % 2 == 1)
            {
                result = pair.first;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}
