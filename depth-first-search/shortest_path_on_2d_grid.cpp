#include <bits/stdc++.h>
using namespace std;
// declare grid in global;
char grid[105][105];
bool vis[105][105];
int level[105][105];
// declare 4 move
vector<pair<int,int>>d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;


// check valid move
bool valid(int i,int j){
    if(i<0 || i >= n || j < 0 || j>=m){
        return false;

    }
    return true;


}

void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty()){
        pair<int,int> parent = q.front();
        q.pop();
        int par_i = parent.first;
        int par_j = parent.second;

        for(int i = 0;i<4;i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj]= true;
                level[ci][cj] = level[par_i][par_j] +1;
            }
        }
    }
    

}

int main()
{

    cin >> n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
           cin >> grid[i][j];
        }
    }

    // input src row and src column
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl;
    return 0;
}   