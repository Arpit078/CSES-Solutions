#include<bits/stdc++.h>
using namespace std;

void dijkstra(pair<int,int> A, pair<int,int> B, vector<string>& graph){
    int n = graph.size();
    int m = graph[0].size();
    map<int, vector<pair<int,char>>> mp;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'A' || graph[i][j] == 'B' || graph[i][j] == '.'){
                for(auto dir : directions){
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if(x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'A' || graph[x][y] == 'B')){
                        int src = i*m + j;
                        if(mp.find(src) == mp.end())mp[src] = {};
                        int point  = x*m + y;
                        mp[src].push_back({point, 1});
                    }
                }
            }
        }
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    int src = A.first*m + A.second;
    int dest = B.first*m + B.second;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});


}
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> graph(n);
    for(int i=0;i<n;i++){
        getline(cin, graph[i]);
    } 
    pair<int,int> A;
    pair<int,int> B;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'A'){
                A.first = i;
                A.second = j;
            }else if(graph[i][j] == 'B'){
                B.first = i;
                B.second = j;
            }
        }
    }
}