// I love DP ..... of my crush
int dp[301][301];
long long mod = 1e9+7;
// ind // target
// fuck you pow function 
class Solution {
    int helper(int ind , int sum , int n , int x)
    {
        long long  value = pow(ind,x);
        if(sum==0)
        {
            return 1;
        }
        if(value>sum)
        {
            return 0;
        }
        if(sum<0)
        {
            return 0;
        }
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
      
        int n_pick = helper(ind+1, sum,n,x);
        int pick =0;
       
            pick=helper(ind+1,sum-value,n,x);
        
       

        return dp[ind][sum]=(pick%mod+n_pick%mod)%mod;

    }
public:
    int numberOfWays(int n, int x) {
          memset(dp,-1,sizeof(dp));
          return helper(1,n,n,x);      
    }
};