#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

// union

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
    vector<pair<int, int>> remove_edge;
    vector<pair<int, int>> create_edge;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            remove_edge.push_back({a, b});
        }
        else
        {
            dsu_union(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int leader1 = dsu_find(1);
        int leader2 = dsu_find(i);
        if (leader1 != leader2)
        {
            create_edge.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << create_edge.size() << endl;
    for (int i = 0; i < remove_edge.size(); i++)
    {
        cout << remove_edge[i].first << ' ' << remove_edge[i].second <<  ' ' << create_edge[i].first << ' ' << create_edge[i].second << endl;
    }

    return 0;
}