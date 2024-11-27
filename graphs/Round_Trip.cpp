#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int>& path, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    path.push_back(node);

    for(int child : adj[node]){
        if(!vis[child]){
            if(dfs(child, node, path, adj, vis)) {
                // Check if the cycle is completed
                if (path.front() != child || path.size() > 2) {
                    return true;
                }
            }
        } else if(child != parent) { 
            // Cycle detected
            path.push_back(child);
            return true;
        }
    }

    path.pop_back(); // Backtrack
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n+1, 0);
    vector<int> path;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i, 0, path, adj, vis)) {
                auto cycleStart = find(path.begin(), path.end(), path.back());
                if (cycleStart != path.end() && path.end() - cycleStart > 2) {
                    path.erase(path.begin(), cycleStart);
                    cout << path.size() << endl;
                    for(int it : path) {
                        cout << it << " ";
                    }
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
