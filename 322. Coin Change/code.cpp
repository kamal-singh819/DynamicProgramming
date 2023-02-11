//Question Link -  https://leetcode.com/problems/coin-change/description/ 
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

      //fill the first row and first column
        for(int i=0; i<n+1; i++){
            for(int j=0; j<amount+1; j++){
                if(j == 0)
                    dp[i][j] = 0;
                if(i == 0)
                    dp[i][j] = INT_MAX-1;
            }
        }

      // filled second row
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(j%coins[0] == 0)
                    dp[i][j] = j/coins[0];
                else
                    dp[i][j] = INT_MAX-1;
            }
        }

      //now fill rest of the rows and columns---------------
        for(int i=2; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1] <= j)
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        if(dp[n][amount] == INT_MAX-1)
            return -1;
        
        return dp[n][amount];
        
    }
};
