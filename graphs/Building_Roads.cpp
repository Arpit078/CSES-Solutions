#include<bits/stdc++.h>
using namespace std;

void dfs(int i, map<int, vector<int>>& mp, vector<int>& vis){
    int n = mp.size();
    if(i > n || vis[i] == 1) return;
    vis[i] = 1;
    for(int j=0; j<mp[i].size(); j++){
        int neigh = mp[i][j];
        dfs(neigh, mp, vis);        
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for(int i=0;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(mp.find(a) == mp.end())mp[a] = {};
        if(mp.find(b) == mp.end())mp[b] = {};
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=1;i<= n;i++){
        if(mp.find(i) == mp.end())mp[i] = {};
    }
    vector<int> vis(n+1, 0);
    vector<int> components;
    for(int i=1; i<=n ; i++){
        if(!vis[i]){
            dfs(i, mp, vis);
            components.push_back(i);
        }
    }
    int k = components.size();
    cout<<k - 1<<endl;
    for(int i=0; i+1<k; i++){
        cout<<components[i]<<" "<<components[i+1]<<endl;
    }
}