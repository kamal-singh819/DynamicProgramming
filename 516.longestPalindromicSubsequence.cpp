//giving TLE

class Solution {
public:
    int dp[1001][1001];
    int lcs(string s, string p, int m, int n){
        //base condition
        if(m == 0 || n == 0)
            return 0;

        if(dp[m][n] != -1)
            return dp[m][n];

        if(s[m-1] == p[n-1])
            return dp[m][n] = 1+lcs(s, p, m-1, n-1);

        else
            return dp[m][n] = max(lcs(s, p, m, n-1), lcs(s, p, m-1, n));           
        
    }

    int longestPalindromeSubseq(string s) {
        string p = s;
        reverse(p.begin(), p.end());

        int m = s.length(); 
        int n = m;
        memset(dp, -1, sizeof(dp));

        return lcs(s, p, m, n); //length is same of both the strings
        
    }
};
