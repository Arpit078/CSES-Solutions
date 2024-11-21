#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(int parent, int node, map<int,vector<int>>& mp, vector<int>& vis){
    for(auto child : mp[node]){
        if(child  != parent){
            dfs(node, child, mp, vis);
            if(!vis[child] && !vis[node]){
                vis[child] = 1;
                vis[node] = 1;
                ans ++;
            }
        }
    }
}

int main(){
    int n;
    cin>> n;
    map<int, vector<int>> mp;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        if(mp.find(a) == mp.end())mp[a] = {};
        if(mp.find(b) == mp.end())mp[b] = {};
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i =1; i<=n; i++){
        if(mp.find(i) == mp.end())mp[i] = {};
    }
    vector<int> vis(n+1, 0);
    dfs(0, 1, mp, vis);
    cout<<ans<<endl;
}