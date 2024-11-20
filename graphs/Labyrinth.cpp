#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, vector<vector<char>>& graph, vector<vector<int>>& vis){
    int n = graph.size();
    int m = graph[0].size();
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1)return false;
    vis[x][y] = 1;
    if(graph[x][y] == '#'){
        return false;
    }
    return true;
}

bool bfs(pair<int,int> A, vector<vector<char>>& graph, string& path, vector<vector<int>>& vis, vector<vector<char>>& pathBox){
    queue<pair<int,int>> q;
    q.push(A);
    vis[A.first][A.second] = 1;
    while(!q.empty()){
        pair<int,int> node = q.front();
        int x = node.first;
        int y = node.second;
        q.pop();
        if(graph[x][y] == 'B'){
            while(node != A){
                path.push_back(pathBox[x][y]);
                char dir = pathBox[x][y];
                if(dir == 'R')y--;
                else if(dir == 'L')y++;
                else if(dir == 'U')x++;
                else x--;
                node = {x, y};
            }
            return true;
        }
        if(isValid(x+1, y, graph, vis)){
            q.push({x+1,y});
            pathBox[x+1][y] = 'D';
        }
        if(isValid(x-1, y, graph, vis)){
            q.push({x-1,y});
            pathBox[x-1][y] = 'U';
        }        
        if(isValid(x, y+1, graph, vis)){
            q.push({x,y+1});
            pathBox[x][y+1] = 'R';
        }        
        if(isValid(x, y-1, graph, vis)){
            q.push({x,y-1});
            pathBox[x][y-1] = 'L';
        }
    }
    return false;
}
int main()
{
    int n, m;
	cin>>n>>m;
	pair<int,int> A;
	vector<vector<char>> graph(n, vector<char>(m));
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'A')A = {i,j};
        }
    }
    string path = "";
    vector<vector<int>> vis(n , vector<int>(m, 0));
    vector<vector<char>> pathBox(n, vector<char>(m));
	if(bfs(A, graph, path, vis, pathBox) == true){
		cout<<"YES"<<endl<<path.size()<<endl;
		while(path.size() > 0) cout<<path.back() , path.pop_back();
	}
	else{
		cout<<"NO";
	}
}