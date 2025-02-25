#include <bits/stdc++.h>
using namespace std;
int parent[1005];

int dsu_find(int node) // 0(logN)
{
    // use recursion
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    return leader;
}

int main()
{

    memset(parent, -1, sizeof(parent));

    // manualy set parent because we not learn unior
    parent[0] = 1;
    parent[1] = -1;
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;
    parent[5] = 3;

    cout << dsu_find(4) << endl;

    return 0;
}