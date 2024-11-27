#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
int f(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& dp){
    int n = grid.size();
    if(i >= n || j >= n)return 0;
    if(grid[i][j] == '*')return 0;
    if(i == n-1 && j == n-1)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = (f(i+1, j, grid, dp) + f(i, j+1, grid, dp))%MOD;
}

int main(){
    int n;
    cin>> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    // for(auto it : grid){
    //     for(char x : it)cout<<x<<" ";
    //     cout<<endl;
    // }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<< f(0,0,grid, dp);
}