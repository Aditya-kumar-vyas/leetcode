class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>b(n*n, -1); //0 indexed
 
        for (int i = n-1, cnt = 0; i >= 0; i--) {
            for (int j = 0; j < n && cnt < b.size(); j++) {
                if (board[i][j] != -1) {
                    b[cnt] = board[i][j] - 1;
                }
                cnt++;
            }
            i--;
            for (int j = n-1; j >= 0 && cnt < b.size(); j--) {
                if (board[i][j] != -1) {
                    b[cnt] = board[i][j] - 1;
                }
                cnt++;
            }
        }

        vector<int>dist(n*n, INT_MAX); //no. of moves to reach i
        queue<int>q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int i = 1; i <= 6 && curr+i < b.size(); i++) {
                int next = b[curr+i] != -1 ? b[curr+i] : curr+i;
                if (dist[next] == INT_MAX) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return dist[n*n-1] == INT_MAX ? -1 : dist[n*n-1];
    }
};