class Solution {
    int dp[1001][26][26];
    int helper(int ind , int start , int end ,vector<string>& v)
    {
        if(ind>=v.size())
        {
            return 0;
        }
        // joining from front 
        if(dp[ind][start][end]!=-1)
        {
            return dp[ind][start][end];
        }
        int ans =1e9;
        ans = min(ans,(int)v[ind].size()-(end+'a'==v[ind][0]) + helper(ind+1,start,v[ind].back()-'a',v));
        ans=min(ans,(int)v[ind].size()-(v[ind].back()==start+'a') + helper(ind+1,v[ind][0]-'a',end,v));
        return dp[ind][start][end]=ans ;
        
    }
public:
    int minimizeConcatenatedLength(vector<string>& v) {
        int n = v.size();

        // I need size 
        memset(dp,-1,sizeof(dp));
        return  v[0].size()+helper(1 ,v[0][0]-'a', v[0].back()-'a', v);



        
    }
};