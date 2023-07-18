class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> ans;
        int n = nums.size();
        int m = moveFrom.size();
        for(int i =0 ; i<n ; i++)
        {
            ans.insert(nums[i]);
        }
        for(int i =0 ; i<m ; i++)
        {
            if(ans.find(moveFrom[i])!=ans.end())
            {
                ans.erase(moveFrom[i]);
                ans.insert(moveTo[i]);
            }
        }
        vector<int> ans1;
        for(auto it : ans)
        {
            ans1.push_back(it);
        }
        return ans1;
        
    }
};