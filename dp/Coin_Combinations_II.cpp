#include<bits/stdc++.h>
using namespace std;

void topDown(int target, vector<int> combination, vector<int>& coins, set<vector<int>>& checker){
    if(target < 0)return;
    if(target == 0){
        sort(combination.begin(), combination.end());
        checker.insert(combination);
        return;
    }
    for(int coin : coins){
        if(coin <= target){
            combination.push_back(coin);
            topDown(target-coin, combination, coins, checker);
        }
    }
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    vector<int> combination;
    set<vector<int>> checker;

    // topDown(x, combination, coins, checker); // gives tle and memory overflow
    // cout<< checker.size()<<endl;
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int coin : coins){
        for(int sum = 1; sum <= x; sum++){
			if (sum - coin >= 0) {
                dp[sum] += dp[sum - coin];
                dp[sum] = dp[sum]%1000000007;
            }
        }
    }
    cout<<dp[x];
}
