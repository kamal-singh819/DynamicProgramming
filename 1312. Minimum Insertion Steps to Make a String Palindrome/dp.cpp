//exact same code for deletion--------------------------

class Solution {
    private:
    int lcsFunction(string x, string y, int m, int n){
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        //no need of initialization because 0 is already filled in dp----
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(x[i-1] == y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
            }
        }
        return dp[m][n];
    }
public:
    int minInsertions(string s) {
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        int n = m; //n is the length of t;

        int lps = lcsFunction(s, t, m, n); // lcs & lps are same here because t = Reverse(s)

        int minNoOfInsertion = m-lps;

        return minNoOfInsertion;     
    }
};
