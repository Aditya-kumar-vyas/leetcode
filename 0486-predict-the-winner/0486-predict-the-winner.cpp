// classic dp 
// game dp 
// dp[start][end][turn]
// optimal idea is take the maximum element
long long dp[22][22];
class Solution {
    long long  helper(int start , int end ,vector<int>& nums)
    {
        if(start>end)
        {
            return 0;
        }
        if(start==end)
        {
            return  nums[start]; 
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        long long ans = nums[start]-helper(start+1,end,nums);
        ans=max(ans,(long long )nums[end]-helper(start,end-1,nums));
        return dp[start][end]=ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        long long sum =0;
        for(int i =0 ; i<n ; i++)
        {
            sum+=nums[i];
        }

        long long ans1 = helper(0,n-1,nums);
        if(ans1>=0)
        {
            return true;
        }
        return false;

        
    }
};