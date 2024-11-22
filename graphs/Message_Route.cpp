#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int n, map<int,vector<int>>& mp, vector<int>& vis, vector<int>& path){
    if(i > n || vis[i] == 1)return false;
    if(i == n)return true;
    vis[i] = 1;
    for(int child : mp[i]){
        bool found = dfs(child, n , mp, vis, path);
        if(found){
            path.push_back(child);
            return true;
        }
    }
    return false;
}

void dijkstra(int n, map<int,vector<int>>& mp){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({1, 1});
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(int child : mp[node]){
            if(d + dist[node] < dist[child]){
                dist[child] = d + dist[node];
                parent[child] = node;
                pq.push({1, child});
            }
        }
    }
    if(dist[n] != INT_MAX){
        cout<<dist[n] + 1<<endl;
        vector<int> path;
        int i = n;
        while(parent[i] != i){
            path.push_back(parent[i]);
            i = parent[i];
        }
        while(!path.empty()){
            cout<<path.back()<<" ";
            path.pop_back();
        }
        cout<< n <<endl;
        
    }else cout<< "IMPOSSIBLE"<<endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(mp.find(a) == mp.end())mp[a] = {};
        if(mp.find(b) == mp.end())mp[b] = {};
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=1; i < n; i++){
        if(mp.find(i) == mp.end())mp[i] = {};
    }
    // vector<int> vis(n+1, 0);
    // vector<int> path;
    // bool found = dfs(1, n, mp, vis, path); // gives path only not the shortest path!
    // if(found){
    //     cout<<path.size()+1<<endl;
    //     cout<<1<<" ";
    //     while(path.size() > 0){
    //         cout<<path.back()<<" ";
    //         path.pop_back();
    //     }
        
    // }else cout<< "IMPOSSIBLE"<<endl;

    dijkstra(n, mp);
}