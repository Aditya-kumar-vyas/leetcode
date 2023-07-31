int vis[203];
class Solution {
    void dfs(int node,vector<int> adj[],int vis[])
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        memset(vis,0,sizeof(vis));
        for(int i=0 ; i<n ; i++ )
        {
            for(int j =0 ; j<n ; j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int cnt =0;
        for(int i =0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt ;


        
    }
};