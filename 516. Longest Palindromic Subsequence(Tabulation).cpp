class Solution {
    private:
    int lcs(string s, string p, int n){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        //initialization-------------
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        //main code for choice diagram------------
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == p[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
            }
        }
        return dp[n][n];
    }
public:
    int longestPalindromeSubseq(string s) {
        string p = s;
        reverse(p.begin(), p.end());

        int n = s.length(); 

        return lcs(s, p, n); //length is same of both the strings
        
    }
};
