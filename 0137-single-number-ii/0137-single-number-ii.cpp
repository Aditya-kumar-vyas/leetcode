class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int tn=-1;
        int tn1 =0;
        int tn2=0;
        for(int i =0 ; i<n ; i++)
        {
            int ctn = (tn & nums[i]);
            int ctn1 = (tn1 & nums[i]);
            int ctn2 = (tn2 & nums[i]);

             tn=tn & (~ctn);
             tn1 = tn1 | ctn;

             tn1= tn1 & (~ctn1);
             tn2 = tn2 | ctn1;
             
             tn2= tn2 & (~ctn2);
             tn = (tn|ctn2);

        }
        return tn1;
    }
};