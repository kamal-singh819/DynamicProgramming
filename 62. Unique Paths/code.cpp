class Solution {
    private:
    int answer(int i, int j, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i >= m || j >= n)
            return 0;
        else if(i == m-1 && j == n-1)
            return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = answer(i+1, j, m, n, mat, dp) + answer(i, j+1, m, n, mat, dp);
    }
public:
    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        vector<vector<int>> mat(m, vector<int> (n, 0));
        return answer(i,j,m,n,mat, dp);     
    }
};
