class Solution{
  private:
    void subsetSum(int *arr, int n, int range, vector<int> &s1PossibleSum){
        vector<vector<bool>> dp(n+1, vector<bool> (range+1, false));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<range+1; j++){
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<range+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int z;
        if(range%2 == 0)
            z = (range/2) + 1;
        else if(range%2 != 0)
            z = (range+1)/2;
            
        for(int j=0; j<z; j++){
            if(dp[n][j] == true)
                s1PossibleSum.push_back(j);
        }
    }
  public:
	int minDifference(int arr[], int n)  { 
	    long long range = 0;
	    for(int i=0; i<n; i++){
	        range += arr[i];
	    }
	    
	    //s1+s2 = range
	    //s2-s1 = range-s1-s1  => s2-s1 = range-2*s1
	    //sum = s2-s1 = range-2*s1
	    vector<int> s1PossibleSum;
	    
	    subsetSum(arr, n, range, s1PossibleSum);
	    
	    int siz = s1PossibleSum.size();
	   // for(int i=0; i<siz; i++)
	   //     cout<<s1PossibleSum[i]<<" ";
	    
	    long long mn = INT_MAX;

	    for(int i=0; i<siz; i++){
	        
	        long long x = 2*s1PossibleSum[i];
	        mn = min(mn, range-x);
	    }

 
	    return mn;
	} 
};
