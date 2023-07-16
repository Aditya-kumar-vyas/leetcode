int dp[201][201];
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
class Solution {
    int helper(int i,int j ,vector<vector<int>>& matrix )
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if(i>=n || i<0 || j>=m || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int cost=1;
        for(int k =0 ; k<=3 ; k++)
        {
             int r1 = i+dx[k];
             int c1= j+dy[k];
             if(r1>=n || r1<0 || c1>=m || c1<0)
             {
                 continue;
             }
             if(matrix[r1][c1]<=matrix[i][j])
             {
                 continue;
             }
             else 
             {
                 cost=max(cost,1+helper(r1,c1,matrix));
             }
        }
        return dp[i][j]=cost;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans =0;
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<m ; j++)
            {
                ans=max(ans,helper(i,j,matrix));
            }
        }
        return ans;

        
    }
};