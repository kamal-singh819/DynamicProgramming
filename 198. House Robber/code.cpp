////////////////////////////    Recursive code  (We are solving from last to start)   ///////////
/////////////           It will give TLE      ///////////////
/*
class Solution {
private:
    int solveRec(vector<int> &nums, int last){
        if(last < 0) return 0;
        if(last == 0) return nums[0];
         //           <------INCLUDE-------------------->  <-------EXCLUDE---------->
        int ans = max(solveRec(nums, last-2) + nums[last], solveRec(nums, last-1) + 0);

        return ans;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solveRec(nums, n-1);
    }
};
*/

////////////////////////Memoization  (Top Down Approach)  //////////////
/*
class Solution{
private:
    int solveMem(vector<int> &nums, int last, vector<int> &dp){
        if(last < 0) return 0;
        if(last == 0) return nums[0];

        if(dp[last] != -1) return dp[last];

        return dp[last] = max(solveMem(nums, last-2, dp) + nums[last], solveMem(nums, last-1, dp) + 0);
    }
public:
    int rob(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return solveMem(nums, n-1, dp);
    }
};
*/


///////////////////////////   Tabulation (Bottom Up)   /////////////////
/*
class Solution{
private:
    int solveTabulation(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n); //n size
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            if(i == 1) 
                dp[i] = max(nums[i], 0+dp[i-1]);
            else
                dp[i] = max(nums[i]+dp[i-2], 0+dp[i-1]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int> &nums){
        return solveTabulation(nums);
    }
};
*/


///////////////////////////  Space Optimization Tabulation (Bottom Up)   /////////////////
class Solution{
private:
    int solveTabulation(vector<int> &nums){
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1; i<n; i++){
                int ans = max(nums[i]+prev2, 0+prev1);
                prev2 = prev1;
                prev1 = ans;
        }
        return prev1;
    }
public:
    int rob(vector<int> &nums){
        return solveTabulation(nums);
    }
};
