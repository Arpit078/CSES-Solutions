#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int i, vector<vector<int>>& adj, vector<int>& team){
    int n = adj.size()-1;
    queue<int> q;
    q.push(i);
    team[i] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int child : adj[node]){
            if(team[child] == team[node]){
                return false;
            }
            if(team[child] == -1){
                team[child] = team[node] == 1 ? 2 : 1;
                q.push(child);
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout<<team[i] << " ";
    // }
    return true;

}   

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i< m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for(int i=1;i<=n;i++){
    //     for(int x : adj[i]){
    //         cout<<x << " ";
    //     }
    //     cout<<endl;
    // }
    vector<int> team(n+1, -1);
    bool flag = false;
    for(int i=1; i<=n;i++){
        if(team[i] == -1){
            flag = isBipartite(i, adj, team);
            if(!flag){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<team[i] << " ";
    }
    return 0;
}