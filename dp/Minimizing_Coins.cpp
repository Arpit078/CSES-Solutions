#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0; 

    for (int coin : coins) {
        for (int j = coin; j <= x; j++) {
            if (dp[j - coin] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
    return 0;
}

/*
Step-by-Step Explanation:
Initialization:

dp[0] = 0: It takes 0 coins to make the sum 0.
All other values in dp are initialized to INT_MAX (impossible to achieve at first).
Iterating Through Coins: For each coin, we iterate through possible sums (j) from coin to x. For each sum j:

If we can make the sum j - coin (i.e., dp[j - coin] != INT_MAX), then:
    dp[j]=min(dp[j],dp[j−coin]+1)
This checks whether including the current coin reduces the number of coins needed for the sum j.
Final Result:

After processing all coins, dp[x] will give the minimum number of coins needed to form the sum x.
If dp[x] == INT_MAX, it means x is not achievable with the given coins, so we return -1.
Example Walkthrough:
Input:
plaintext
Copy code
n = 3, x = 11
coins = [1, 5, 7]
Step 1: Initialize dp Array
Initialize dp of size x + 1 (from 0 to 11):
plaintext
Copy code
dp = [0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF]
(INF represents INT_MAX here for clarity.)

Step 2: Process Each Coin
Coin = 1:

Iterate j from 1 to 11:
For j = 1: dp[1] = min(dp[1], dp[1 - 1] + 1) = min(INF, 0 + 1) = 1
For j = 2: dp[2] = min(dp[2], dp[2 - 1] + 1) = min(INF, 1 + 1) = 2
Repeat for all sums up to 11:
plaintext
Copy code
dp = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Coin = 5:

Iterate j from 5 to 11:
For j = 5: dp[5] = min(dp[5], dp[5 - 5] + 1) = min(5, 0 + 1) = 1
For j = 6: dp[6] = min(dp[6], dp[6 - 5] + 1) = min(6, 1 + 1) = 2
Repeat for all sums up to 11:
plaintext
Copy code
dp = [0, 1, 2, 3, 4, 1, 2, 3, 4, 5, 2, 3]
Coin = 7:

Iterate j from 7 to 11:
For j = 7: dp[7] = min(dp[7], dp[7 - 7] + 1) = min(3, 0 + 1) = 1
For j = 8: dp[8] = min(dp[8], dp[8 - 7] + 1) = min(4, 1 + 1) = 2
Repeat for all sums up to 11:
plaintext
Copy code
dp = [0, 1, 2, 3, 4, 1, 2, 1, 2, 3, 2, 3]
Step 3: Final Result
dp[11] = 3: The minimum number of coins to form the sum 11 is 3 (7 + 1 + 1).
*/ 