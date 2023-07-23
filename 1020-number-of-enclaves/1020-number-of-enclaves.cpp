// standard question
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
int vis[501][501];
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        // first row and last row 
        for(int i =0 ; i<m ; i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==1)
            {
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int i =0 ; i<n ; i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
           
            for(int i =0 ; i<4 ; i++)
            {
                int new_r=r+dx[i];
                int new_c = c+dy[i];
                if(new_r>=0 and new_r<n and new_c>=0 and new_c<m and !vis[new_r][new_c] and grid[new_r][new_c]==1)
                {
                    q.push({new_r,new_c});
                    vis[new_r][new_c]=1;
                }
            }
        }
        int cnt =0;
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<m ; j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt ;

        
    }
};