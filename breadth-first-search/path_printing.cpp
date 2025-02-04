#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : adj_list[p])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[p] + 1;
                parent[child] = p;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, des;
    cin >> src >> des;
    bfs(src);

    // for(int i = 0;i<n;i++){
    //     cout << i << " parent hossa=> " << parent[i] << endl;
    // }

    vector<int> path;
    int node = des;
    while (node != -1)
    {
        //    cout << node << " ";
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    for (int val : path)
    {
        cout << val << ' ';
    }

    // print level of destination node
    // cout << level[des] << endl;
    return 0;
}