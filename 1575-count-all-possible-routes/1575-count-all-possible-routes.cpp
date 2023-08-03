
int mod = 1e9+7;
int dp[101][201];

class Solution {
    int helper(int curr ,  int fuel,vector<int>& locations,  int finish)
    {
        if(fuel<0)
        {
            return 0;
        }
        int ans1=0;
         if(dp[curr][fuel]!=-1)
        {
            return dp[curr][fuel];
        }
        if(curr==finish)
        {
           ans1++;
        }
       
        // recurrence
       
        int n = locations.size();
        for(int i =0 ; i<n ; i++)
        {
             if(i!=curr)
             {
                ans1=ans1%mod+helper(i,fuel-abs(locations[curr]-locations[i]),locations,finish)%mod;
             }
        }
        return dp[curr][fuel] = ans1%mod ;


    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        memset(dp,-1,sizeof(dp));
        int ans =0;
        ans=helper(start,fuel,locations,finish);
        return ans%mod ;


        
    }
};