int dp[367];
class Solution {
    int helper(int ind ,vector<int>& days, vector<int>& costs)

{ int n = days.size(); 
if(ind>=n)
{
    return 0;
}
if(dp[ind]!=-1)
{
    return dp[ind];
}                                

            int ind1 = upper_bound(days.begin(),days.end(),days[ind])-days.begin();
int ind2 = upper_bound(days.begin(),days.end(),days[ind]+6)-days.begin();
int ind3 = upper_bound(days.begin(),days.end(),days[ind]+29)-days.begin();
long long  ans = INT_MAX;
long long  ans1 = INT_MAX;
long long  ans2 = INT_MAX;

    ans=costs[0]+helper(ind1,days,costs);

    ans1=costs[1]+helper(ind2,days,costs);

    ans2=costs[2]+helper(ind3,days,costs);

dp[ind]=min(ans,min(ans1,ans2));
return dp[ind];


    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // int m = costs.size();
        memset(dp,-1,sizeof(dp));
       
        return helper(0,days,costs);

        
        
    }
};