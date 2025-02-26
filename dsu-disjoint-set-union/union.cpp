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

    // union
    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);

    // print
    for (int i = 0; i < 6; i++)
    {
        cout << i << ' ' << parent[i] << endl;
    }
    return 0;
}