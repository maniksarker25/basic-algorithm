#include <bits/stdc++.h>
using namespace std;

bool vis[100];
vector<int>adj_list[105];
int parent_array[105];
bool isCycle;



void dfs(int src){
   vis[src] = true;
   for(int child : adj_list[src]){
    if(vis[child] && parent_array[src] != child){
        isCycle = true;
    }
    if(!vis[child]){
        parent_array[child] = src;
        dfs(child);
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
            dfs(i);
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