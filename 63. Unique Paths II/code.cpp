class Solution {
private:
    int countPaths(int i, int j, int &m, int &n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        if(i == m-1 && j == n-1) 
            return 1;

        if(dp[i][j] != -1) 
            return dp[i][j];
        
        else
            return dp[i][j] = countPaths(i+1, j, m, n, obstacleGrid, dp) + countPaths(i, j+1, m, n, obstacleGrid, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]) return 0;
        
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return countPaths(0, 0, m, n, obstacleGrid, dp); 
    }
};
