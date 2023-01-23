//This problem is same as "Count the no. of subsets with a given difference"
class Solution {
private:    
    int noOfSubset(vector<int> &arr, int n, int sum){
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i == 0)
                   dp[i][j] = 0;
                if(j == 0)
                   dp[i][j] = 1;   
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];    
            }
        }
        return dp[n][sum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target = abs(target);
        int arrsum = 0;
        for(int i=0; i<n; i++){
            arrsum += nums[i];
        }
        /*
        sum(s1) - sum(s2) = target -----(i)
        sum(s1) + sum(s2) = arrsum -----(ii)

        Now add both of the eqn.---

        sum(s1) = (target+arrsum)/2

        Now we have to find the no. of subsets with the given sum = sum(s1)...
        */
        int sum = (target+arrsum)/2;
        if(arrsum < target || (arrsum+target)%2 != 0)
            return 0;


        return noOfSubset(nums, n, sum);     
    }
};
