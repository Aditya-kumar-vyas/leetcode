int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};
int vis[201][201] ;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        memset(vis,0,sizeof(vis));
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        // first row and last row 
        for(int i =0 ; i<m ; i++)
        {
            if(board[0][i]=='O' and  vis[0][i]==0)
            {
                vis[0][i]=1;
                q.push({0,i});
            }
            if(board[n-1][i]=='O' and vis[n-1][i]==0)
            {
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        for(int i =0 ; i<n ; i++)
        {
            if(board[i][0]=='O' and  vis[i][0]==0)
            {
                vis[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O' and vis[i][m-1]==0)
            {
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col]=1;
            for(int i =0 ; i<4 ; i++)
            {
                int n_row = row+dx[i];
                int n_col = col+dy[i];
                if(n_row>=0 and n_row<n and n_col>=0 and n_col<m and !vis[n_row][n_col] and board[n_row][n_col]=='O')
                {
                    q.push({n_row , n_col});
                }
            }
        }
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<m ; j++)
            {
                if(board[i][j]=='O' and !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
        

    }
};