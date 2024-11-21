#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int f(int target, vector<int>& coins, vector<int>& dp){
    if(target < 0)return 0;
    if(target == 0)return 1;
    if(dp[target] != 0)return dp[target];
    for(int i=0; i<coins.size(); i++){
        if(coins[i] <= target){
            dp[target] = (dp[target] + f(target - coins[i], coins, dp))%MOD;
        }
    }
    return dp[target];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    vector<int> dp(x+1, 0);

    //recursive is slower, gives tle on two test cases.
    // int ans = f(x, coins, dp);
    // printf("%d",ans);


    //bottom up is faster
    dp[0] = 1;
	for (int weight = 0; weight <= x; weight++) {
		for (int i = 0; i < n; i++) {
			if (weight - coins[i] >= 0) {
				dp[weight] += dp[weight - coins[i]];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';

}