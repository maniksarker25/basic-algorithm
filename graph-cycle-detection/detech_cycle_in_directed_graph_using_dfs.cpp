#include <bits/stdc++.h>
using namespace std;

bool vis[100];
vector<int>adj_list[105];
bool path_visit[105];
bool isCycle;



void dfs(int src){
   vis[src] = true;
   path_visit[src] = true;
   for(int child : adj_list[src]){
    if(vis[child] && path_visit[child]){
        isCycle = true;
    }
    if(!vis[child]){
        dfs(child);
    }
   }

   // return 
   path_visit[src] = false;
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
    }
    memset(vis,false,sizeof(vis));
    memset(path_visit,false,sizeof(path_visit));
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