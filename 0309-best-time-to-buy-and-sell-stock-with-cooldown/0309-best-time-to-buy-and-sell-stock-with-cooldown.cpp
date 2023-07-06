class Solution {
    long long  helper(int ind , int buy , vector<int>& prices,vector<vector<long long >>&dp)
    {
        if(ind>=prices.size())
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        long long profit =0;
        if(buy)
        {
            profit = max(-prices[ind] + helper(ind+1,0,prices,dp),helper(ind+1,1,prices,dp));
        }
        else
        {
            profit=max(prices[ind]+helper(ind+2,1,prices,dp),helper(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;



    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long >> dp(n+1,vector<long long >(2,-1));
        return helper(0,1,prices,dp);
        
    }
};