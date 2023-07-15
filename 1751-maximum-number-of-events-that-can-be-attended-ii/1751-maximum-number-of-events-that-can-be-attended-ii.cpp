

class Solution {
    int helper(int ind , vector<vector<int>>& events, int k,vector<vector<int>>& dp)
    {
          if(ind>=events.size() || k==0)
          {
              return 0;
          }
          if(dp[ind][k]!=-1)
          {
              return dp[ind][k];
          }
          int i ;
          for( i = ind+1 ; i<events.size() ; i++)
          {
               if(events[ind][1]<events[i][0])
               {
                   break;
               }
          }
          
          return dp[ind][k]=max(events[ind][2]+helper(i,events,k-1,dp),helper(ind+1,events,k,dp));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1 , vector<int>(k+1,-1));
        return helper(0,events,k,dp);

    }
};