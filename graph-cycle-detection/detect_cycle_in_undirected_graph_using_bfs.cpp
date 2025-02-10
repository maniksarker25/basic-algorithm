#include <bits/stdc++.h>
using namespace std;

bool vis[100];
vector<int>adj_list[105];
int parent_array[105];
bool isCycle;
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int child : adj_list[parent]){
            if(vis[child] && parent_array[parent] != child){
                isCycle = true;
            }
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
                parent_array[child] = parent;
            }
        }

    }
}

int main()
{
    int n ,e;
    cin >> n >> e;
    while (e--)
    {
       int a , b;
       cin >> a >> b;
       adj_list[a].push_back(b);
       adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent_array,-1,sizeof(parent_array));
    isCycle = false;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    
    if(isCycle){
        cout << "Cycle detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }
    
    return 0;
}