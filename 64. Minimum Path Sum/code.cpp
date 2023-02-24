//              MEMOIZATION        //////////////////////

class Solution {
private:
    int fun(int i, int j, int m, int n, vector<vector<int>>& grid, int down, int right, vector<vector<int>> &dp){
        if(i >= m || j >= n){
            return 9999; //out of boundary jaa raha hai agar to return high value, taki function minimum return kare..
        }
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        down = (grid[i][j] + fun(i+1, j, m, n, grid, down, right, dp));
        right = (grid[i][j] + fun(i, j+1, m, n, grid, down, right, dp));

        return dp[i][j] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i=0;
        int j=0;
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return fun(i, j, m, n, grid, 0, 0, dp);
    }
};
