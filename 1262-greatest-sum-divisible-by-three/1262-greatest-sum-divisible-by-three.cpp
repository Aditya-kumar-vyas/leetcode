class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&nums,int idx,int r)
    {
        if(idx>=nums.size())
        {
            if(r==0)
            {
                return 0;
            }
            return -10000;
        }
        if(dp[idx][r]!=-1)
            return dp[idx][r];
        int x=nums[idx]+solve(nums,idx+1,(r+nums[idx])%3);
        int y=solve(nums,idx+1,r);
        return dp[idx][r]=max(x,y);
    }
    int maxSumDivThree(vector<int>& nums) 
    {
        int n=nums.size();
        dp.resize(n+1,vector<int>(3,-1));
        return solve(nums,0,0);
    
        
    }
};
