int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        q.push({sr,sc});
        int inicolor = image[sr][sc];
        // image[sr][sc]=color;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c]=1;
            image[r][c]=color;
            for(int i =0 ; i<4 ; i++)
            {
                 int ne_r = r+dx[i];
                 int ne_c = c+dy[i];
                 if(ne_r>=0 and ne_r<n and ne_c>=0 and ne_c<m and vis[ne_r][ne_c]==0 and image[ne_r][ne_c]==inicolor)
                 {
                    
                      q.push({ne_r,ne_c});
                 }
            }


        }
        return image;
        
    }
};