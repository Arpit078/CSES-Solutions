#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int sum, int target, vector<int>& dp) {
    if (sum > target) return 0;       // No ways if sum exceeds target
    if (sum == target) return 1;      // Found one way to reach target
    if (dp[sum] != -1) return dp[sum]; // Use memoized result if available

    int ways = 0;                     // Count the number of ways
    for (int i = 1; i <= 6; i++) {    // Iterate over dice faces
        ways = (ways + f(sum + i, target, dp)) % MOD; // Recursive call with modulo
    }
    dp[sum] = ways;                   // Memoize the result with modulo
    return dp[sum];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);        // Initialize DP array with -1
    int ans = f(0, n, dp);            // Start recursion with sum 0
    cout << ans << endl;              // Print the result
    return 0;
}
