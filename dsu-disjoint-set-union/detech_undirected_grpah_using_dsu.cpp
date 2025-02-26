#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int group_size[1005];
// dsu find
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    return leader;
}

// union by size----------------

void dsu_union(int node_1, int node_2)
{
    int leader1 = dsu_find(node_1);
    int leader2 = dsu_find(node_2);

    // check group size
    if (group_size[leader1] >= group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{

    memset(parent, -1, sizeof(parent));
    memset(group_size, 1, sizeof(group_size));
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        // detech cycle if
        if (leaderA == leaderB)
        {
            cycle = true;
        }
        // if not cycle make union
        dsu_union(a, b);
    }

    if (cycle)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }
    return 0;
}