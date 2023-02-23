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


//              //More optimized////////////////////

class Solution {
public:
    int uniquePaths(int m, int n) {
        //if a path exist, m-1 move to down will be taken and n-1 move to right will be taken 
        //where m = no. of rows and n = no. of columns

        //then total move = m-1+n-1 = m+n-2

        int N = m+n-2;
        int r = m-1; //we can take n-1 // Use NCr

        long long res = 1;

        for(int i=1; i<=r; i++){
            res = res * (N-r+i)/i;
        }
        return (int)res;
        
    }
};
