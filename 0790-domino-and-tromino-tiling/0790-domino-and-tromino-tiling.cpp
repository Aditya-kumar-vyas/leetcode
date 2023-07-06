const int mod = (int) 1e9+7;
int dp[1001][2][2];
class Solution {
    int helper(int ind , int up ,int down, int n )
    {
        if(ind==n)
        {
            return (up==1 and down==1);
        }
        if(dp[ind][up][down]!=-1)
        {
            return dp[ind][up][down];
        }
        int ans =0;
        if(up==1 and down==1)
        {
            // add vertical 
            ans=(ans%mod + helper(ind+1,1,1,n)%mod)%mod;
            // add two horizontal
            if(ind+2<=n)
            {
                 ans=(ans%mod + helper(ind+2,1,1,n)%mod)%mod;
            }
            // add L
            if(ind+2<=n)
            {
                 ans=(ans%mod + helper(ind+2,0,1,n)%mod)%mod;
            }
            if(ind+2<=n)
            {
                 ans=(ans%mod + helper(ind+2,1,0,n)%mod)%mod;
            }
            
        }
        else 
        {
            if(up==0 and down==1)
            {
               
                 ans=(ans%mod + helper(ind+1,1,1,n)%mod)%mod;
                   ans=(ans%mod + helper(ind+1,1,0,n)%mod)%mod;

            
            }
            else 
            {
                  ans=(ans%mod + helper(ind+1,1,1,n)%mod)%mod;
                    ans=(ans%mod + helper(ind+1,0,1,n)%mod)%mod;
            }

        }
        return dp[ind][up][down]=ans;
    }
public:
    int numTilings(int n) {
        if(n==1)
        {
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,1,1,n);

    }
};