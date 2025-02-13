#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj_list[100];
int distace[105];

void dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    distace[src] = 0;
    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int par_node = p.second;
        int par_distace = p.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_distace = child.second;
            if ((par_distace + child_distace) < distace[child_node])
            {
                distace[child_node] = par_distace + child_distace;
                pq.push({distace[child_node],child_node});
              

            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >>e;

    while (e--)
    {
        int a,b,c;
        cin >> a >>b >>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    for(int i =0;i<n;i++){
        distace[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i =0;i<n;i++){
        cout << i << " =>"<< distace[i] << endl;
    }
    return 0;
}