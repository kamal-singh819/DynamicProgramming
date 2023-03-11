/////////////////   This is recursive solution and will give TLE  /////////////////
/*
class Solution {
private:
    int solve(vector<int> &cost, int n){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        int res = cost[n] + min(solve(cost, n-1) , solve(cost, n-2));
        return res;
    }    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1) return cost[n]; //optional

        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;    
    }
};
*/


/////////////////////   Top-Down Approach (Memoized of recursion)
/*
class Solution {
private:
    int solve(vector<int> &cost, int n, vector<int> &dp){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        if(dp[n] != -1) return dp[n];

        return dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
    public:
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        if(n <= 1) return cost[n]; //optional

        vector<int> dp(n+1, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};
*/


//////////////////////// Bottom-Up Approach (Tabulation)   ////////////////////////
/*
class Solution{
private:
    int solve(vector<int> &cost, int n){
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        if(n <= 1) return cost[n]; //optional

        int ans = solve(cost, n);
        return ans;
    }
};
*/


//////////////////////// Bottom-Up Approach (Tabulation) with Space optimazation /////////////
class Solution{
private:
    int solve(vector<int> &cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<n; i++){
            int ans = cost[i] + min(prev1 , prev2);
            prev2 = prev1;
            prev1 = ans;
        }

        return min(prev1, prev2);
    }
public:
    int minCostClimbingStairs(vector<int> &cost){
        int n = cost.size();
        if(n <= 1) return cost[n]; //optional

        int ans = solve(cost, n);
        return ans;
    }
};
