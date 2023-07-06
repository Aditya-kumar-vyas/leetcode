/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {

    int helper(int ind ,int prev ,vector<vector<int>>&pairs,vector<vector<int>>&dp )
    {
         if(ind==pairs.size())
         {
            return 0;
         }
         if(dp[ind][prev+1]!=-1)
         {
             return dp[ind][prev+1];
         }
        
         int pick = INT_MIN;
         if(prev==-1 || pairs[ind][0]>pairs[prev][1])
         {
             pick=1+helper(ind+1,ind,pairs,dp);
         }
          int n_pick = helper(ind+1,prev,pairs,dp);
         return dp[ind][prev+1]=max(pick,n_pick);
    }
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1,pairs,dp);


    }
};
// @lc code=end

