// typical buy and sell stock
long long mod = 1e9+7;
 int dp[2][1001][1001];
class Solution {
    int helper(int buy , int ind , int k, vector<int> &nums)
    {
        // base case
        if(k==0)
        {
            return 1;
        }
        if(ind==nums.size())
        {
            return 0;
        }


        if(dp[buy][ind][k]!=-1)
        {
            return dp[buy][ind][k];
        }
        int cost =0;
        int pick =0;
        int n_pick=0;
        if(buy)
        {
            pick= helper(1 , ind+1 , k,nums)%mod;
            n_pick=helper(0,ind+1,k,nums)%mod;
            cost=(pick+n_pick)%mod;
            return dp[buy][ind][k]=cost;
            
        }
        else 
        {
            pick = helper(0,ind+1,k,nums)%mod;
            n_pick=helper(1,ind,k-1,nums)%mod;
            cost=(pick+n_pick)%mod;
             return dp[buy][ind][k]=cost;
        }
    }
public:
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        vector<int> nums;
        for(int i = 0 ; i<=n-1 ; i++)
        {
            nums.push_back(i);
        }
        return helper(1,0,k,nums);

        
    }
};