long long  dp[1000001][2];
class Solution {
public:
    long long helper(int ind, int rem, vector<int>& nums, int x){
        int n = nums.size();
        if(ind == n){
            return 0;
        }
        
        if(dp[ind][rem] != -1){
            return dp[ind][rem];
        }
        
        long long notake = helper(ind + 1, rem, nums, x);
        
        long long take = 0;
        if(nums[ind] % 2 == rem){
            take = nums[ind] + helper(ind + 1, rem, nums, x);
        }
        else{
            take = nums[ind] - x + helper(ind + 1, !rem, nums, x);
        }
        
        
        return dp[ind][rem] = max(take, notake);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
    
        return helper(1, nums[0] % 2, nums, x) + nums[0];
    }
};