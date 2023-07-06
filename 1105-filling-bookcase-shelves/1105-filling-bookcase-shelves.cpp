class Solution {
public:
    int dp[1002][1002];
    int maxW;
    int solve(int idx,int shelfWidth,int maxHt,vector<vector<int>>&books)
    {
        if(idx>=books.size())
        {
            return maxHt;
        }

        if(dp[idx][shelfWidth]!=-1)
        return dp[idx][shelfWidth];

        int curWidth = books[idx][0];
        int curHeight = books[idx][1];

        if(curWidth<=shelfWidth)
        {
            int take = 
            solve(idx+1,shelfWidth-curWidth,max(maxHt,curHeight),books);

            int notTake = maxHt+solve(idx+1,maxW-curWidth,curHeight,books);

            return dp[idx][shelfWidth]=min(take,notTake);
        }
        
        return dp[idx][shelfWidth]=
        maxHt+solve(idx+1,maxW-curWidth,curHeight,books);
        
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        maxW=shelfWidth;
        return solve(0,shelfWidth,0,books);
    }
};