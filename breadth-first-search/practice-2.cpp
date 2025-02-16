#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int vis[1005];
int level[1005];
int l;
vector<int> arr;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
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

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    cin >> l;
    bfs(0);
    vector<int> level_arr;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == l)
        {
            level_arr.push_back(i);
        }
    }

    sort(level_arr.begin(), level_arr.end(), greater<int>());

    for (int val : level_arr)
    {
        cout << val << ' ';
    }
    return 0;
}