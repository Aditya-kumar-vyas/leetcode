class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int search=matrix[0].size();
        int n=matrix.size();
        int i=0,j=search-1;
        while(i<n && j>=0)
        {
          if(matrix[i][j]==target)
          {
              return true;
          }
          if(matrix[i][j]>target)
          {
              j--;
          }
          else
          {
              i++;
          }
        }
        return false;
    }
};