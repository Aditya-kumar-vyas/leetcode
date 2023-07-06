class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans =INT_MAX;
        long long sum =0;
        int i =0;
        int j=0;
        while(j<n)
        {
            sum+=nums[j];
            if(sum<target)
            {
                j++;
            }
            else 
            {
                     while(sum>=target)
                     {
                         ans=min(j-i+1,ans);
                         sum-=nums[i];
                         i++;
                         

                     }
                     j++;
            }
        }
        if(ans>=INT_MAX)
        {
            return 0;
        }
        return ans ;
        
    }
};