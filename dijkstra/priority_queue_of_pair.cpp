#include <bits/stdc++.h>
using namespace std;
int main()
{
    // priority queue for normal int
    // priority_queue<int,vector<int>,greater<int>>pq;

    // priority key for pair
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({10,1});
    pq.push({5,2});
    cout << pq.top().first << " " << pq.top().second << endl; 
    return 0;
}