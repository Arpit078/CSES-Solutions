#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init() {
fast_io;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}



int findHeight(int i, map<int, vector<int>>& mp, int parent){
    int h = 0;
    for(int child : mp[i]){
        if(child == parent) continue;
        h = max(h, findHeight(child, mp, i));
    }
    return 1 + h;
}

int findLeafNode(int startingNode, map<int,vector<int>>& mp){
    queue<int> q;
    int n = mp.size();
    vector<int> vis(n+1);
    q.push(startingNode);
    vis[startingNode] = 1;
    int lastNode = startingNode;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int child : mp[node]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                lastNode = child;
            }
        }
    }
    return lastNode;

}
void dfs(int node,int parent, map<int, vector<int>>& mp, vector<vector<int>>& dist, int c, int d){
    dist[node][c] = d;
    for(int child : mp[node]){
        if(child == parent)continue;
        dfs(child, node, mp, dist, c, d+1);
    }
}
int main(){
    init();
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    // // gives TLE, O(n2)
    // for(int i = 1; i <= n; i++){
    //     int h = findHeight(i, mp, -1); 
    //     cout << h - 1 << " ";
    // } 

    int leaf1 = findLeafNode(1, mp);
    int leaf2 = findLeafNode(leaf1, mp);
    vector<vector<int>> dist(n+1, vector<int>(2));
    dfs(leaf1, 0, mp, dist, 1, 0);
    dfs(leaf2, 0, mp, dist, 0, 0);
    for(int i=1; i<=n; i++){
        cout<< max(dist[i][0], dist[i][1]) << " ";
    }
    return 0;
}