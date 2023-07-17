class Solution {
public:
    int helper(int i1,int i2,string s1,string s2,int n1,int n2,vector<vector<int>>& dp)
    {
        if(i1>=n1)
            return n2-i2;
        if(i2>=n2)
            return n1-i1;
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(s1[i1]==s2[i2])
            return helper(i1+1,i2+1,s1,s2,n1,n2,dp);
        int insert=helper(i1,i2+1,s1,s2,n1,n2,dp);
        int del=helper(i1+1,i2,s1,s2,n1,n2,dp);
        int rep=helper(i1+1,i2+1,s1,s2,n1,n2,dp);
        return dp[i1][i2]=1+min(insert,min(del,rep));
    }
    int minDistance(string word1, string word2) {
        
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return helper(0,0,word1,word2,n1,n2,dp);
    }
};