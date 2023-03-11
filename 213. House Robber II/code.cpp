//////     same consecpt as Q. 198

class Solution {
private:
    int solveTabulationSpace(vector<int> &nums, int start, int last){
        int prev2 = 0;
        int prev1 = nums[start];
        for(int i=start+1; i<= last; i++){
            int ans = max(nums[i]+prev2, 0+prev1);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        //divide this problem into two pieces- 1. take first and do not take last 2. do not take first and take last
        int pro1 = solveTabulationSpace(nums, 0, n-2); //take first and do not take last
        int pro2 = solveTabulationSpace(nums, 1, n-1); //do not take first and take last

        return max(pro1, pro2);
    }
};
