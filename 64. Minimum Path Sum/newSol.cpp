// But this is recursive method it will give TLE
/*
class Solution {
private:
    int recFunction(int i, int j, int &m, int &n, vector<vector<int>> &grid){
        if(i >= m || j >= n) return 99999;
        if(i == m-1 && j == n-1) return grid[i][j];

        int down = grid[i][j] + recFunction(i+1, j, m, n, grid);
        int right = grid[i][j] + recFunction(i, j+1, m, n, grid);

        return min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return recFunction(0, 0, m, n, grid);   
    }
};
*/

//Now memoized it-- (DP)
/*
class Solution {
private:
    int memFunction(int i, int j, int &m, int &n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= m || j >= n) return 99999;
        if(i == m-1 && j == n-1) return grid[i][j];
        //before calling function again, look into the dp table
        if(dp[i][j] != -1) return dp[i][j];

        int down = grid[i][j] + memFunction(i+1, j, m, n, grid, dp);
        int right = grid[i][j] + memFunction(i, j+1, m, n, grid, dp);
        return dp[i][j] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return memFunction(0, 0, m, n, grid, dp);
    }
};
*/

//Without memoization (DP)
class Solution{
    public:
    int minPathSum(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                else if(i != 0 && j == 0) grid[i][j] += grid[i-1][j];
                else if(i == 0 && j != 0) grid[i][j] += grid[i][j-1];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
