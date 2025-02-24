#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100005];
int dis[100005];
int n, m;
int parent[100005];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    parent[src] = -1;
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dis = par.first;
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if ((par_dis + child_dis) < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
    dijkstra(1);
    // if there is no path
    if (dis[n] == INT_MAX)
    {
        cout << -1 << endl;
    }
    vector<int> path;
    for (int node = n; node != -1; node = parent[node])
    {
        path.push_back(node);
    }

    reverse(path.begin(), path.end());

    for (int val : path)
    {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}
