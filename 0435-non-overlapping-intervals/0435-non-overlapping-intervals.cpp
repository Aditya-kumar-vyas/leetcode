class Solution {
public:
int bs(int i,int t,vector<vector<int>>& intervals,vector<int>& nums){
    // int latest=100000;
    int l=i+1;
    int r=intervals.size()-1;
    int  latest = lower_bound(nums.begin() , nums.end() , t)-nums.begin();
    return latest;
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<int>mem;
        mem.resize(100000,-1);
        sort(intervals.begin(),intervals.end());
        vector<int> nums;
        for(int i =0 ; i<intervals.size() ; i++)
        {
            nums.push_back(intervals[i][0]);
        }
        return intervals.size()-fun(0, intervals, mem,nums);
    }

    int fun(int i, vector<vector<int>>& intervals, vector<int>& mem , vector<int>& nums){
        if (i>=intervals.size()){
            return 0;
        }

        if(mem[i] != -1){
            return mem[i];
        }

        
        int j=bs(i,intervals[i][1],intervals,nums);



        

        int take = fun(j, intervals, mem,nums)+1;
        int nottake = fun(i+1,intervals,mem,nums);

        mem[i]=max(take, nottake);
        

    return mem[i];


    }
};