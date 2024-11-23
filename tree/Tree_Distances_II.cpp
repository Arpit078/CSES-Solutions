#include<bits/stdc++.h>
using namespace std;
#define ll long long
void findSubtreeLengths(int node, int parent, ll d,  vector<vector<int>>& adj, vector<ll>& subtree, vector<ll>& distances){
    distances[1] += d;
    for(int child : adj[node]){
        if(child != parent){
            findSubtreeLengths(child, node, d+1, adj, subtree, distances);
            subtree[node] += subtree[child];
        }
    }
}

void updateDistances(int node, int parent, int n, vector<vector<int>>& adj, vector<ll>& subtree, vector<ll>& distances){
    for(int child : adj[node]){
        if(child != parent){
            distances[child] = distances[node] + (n - 2*subtree[child]);
            updateDistances(child, node, n,  adj ,subtree, distances); 
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> subtree(n+1, 1);
    vector<ll> distances(n+1, 0);
    findSubtreeLengths(1, 0, 0, adj, subtree, distances);
    updateDistances(1, 0, n, adj, subtree, distances);
    for(int i=1; i<=n; i++){
        cout<< distances[i] << " ";
    }
}