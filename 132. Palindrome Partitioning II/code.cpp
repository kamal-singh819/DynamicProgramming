class Solution{
public:
    bool isPalindrome(string& s, int i, int j){
        if(i==j)return true;
        if(i>j)return true;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
     int solve(string& s, int i, int j, vector<int>&dp){
        if(i>=j)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(isPalindrome(s, i, j))
            return 0;
        
        int ans = INT_MAX;
        int temp_Ans;
        for(int k = i; k <= j-1; k++){
            if(isPalindrome(s, i, k)){
                temp_Ans = 1 + solve(s, i, k, dp) + solve(s, k+1, j, dp);
                ans = min(temp_Ans, ans);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s)
    {
        // code here
        int n = s.size();
        vector<int>dp(n+1, -1);
        return solve(s, 0, n-1, dp);
    }
};
