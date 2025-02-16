#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = 0;
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                level[child] = level[par] + 1;
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        int src, des;
        cin >> src >> des;
        bfs(src);
        cout << level[des] << endl;
    }

    return 0;
}