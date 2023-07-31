int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
class Solution {
    void bfs(int row,int col ,vector<vector<int>>&vis , vector<vector<char>>& grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k = 0 ; k<4 ; k++)
            {
                
            
                    int n_row = row+dx[k];
                    int n_col = col+dy[k];
                    if(n_row>=0 and n_row<n and n_col>=0 and n_col<m and grid[n_row][n_col]=='1' and vis[n_row][n_col]==0)
                    {
                          vis[n_row][n_col]=1;
                          q.push({n_row,n_col});
                    }
                
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt =0;
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<m ; j++)
            {
                 if( vis[i][j]==0 and grid[i][j]=='1' )
                 {
                     cnt++;
                     bfs(i,j,vis,grid);
                 }
            }
        }
        return cnt ;


        
        
    }
};