class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dp(s1, s2, n-1, m-1, memo);
    }

private:
    int dp(string& s1, string& s2, int i, int j, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) {
            int leftToDel = 0;
            while (i >= 0) leftToDel += s1[i--];
            while (j >= 0) leftToDel += s2[j--];
            return leftToDel;
        }

        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) return memo[i][j] = dp(s1, s2, i-1, j-1, memo);
        return memo[i][j] = min(s1[i] + dp(s1, s2, i-1, j, memo), s2[j] + dp(s1, s2, i, j-1, memo));
    }
};