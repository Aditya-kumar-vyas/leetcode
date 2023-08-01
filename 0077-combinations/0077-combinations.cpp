int temp;
class Solution {
    void helper(int val , int size ,int k ,int n ,vector<vector<int>>&ans , vector<int>&ds)
    {      // base case
           if(size<=0)
           {
                 if(ds.size()==k)
                 {
                     ans.push_back(ds);
                 }
                 return ;
           }
           if(val>n)
           {
               return ;
           }
           ds.push_back(val);
           helper(val+1,size-1,k,n,ans,ds);
           ds.pop_back();
           helper(val+1,size,k,n,ans,ds);
          
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;
         temp=k;
         vector<int> ds;
         helper(1,k,k,n,ans,ds);
         return ans ;
        
    }
};