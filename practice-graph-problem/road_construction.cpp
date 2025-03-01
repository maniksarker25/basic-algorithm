#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
int component, mx;
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
    if(leader1 == leader2){
        return;
    }
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }
    component--;
}

int main()
{
    int n, m;
    cin >> n >> m;

    component = n;
    mx = 1;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << component << ' '<< mx << endl;
    }

    return 0;
}