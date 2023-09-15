//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    set<int> s;
    int helper(int idx , int sum , vector<int>&nums ,vector<vector<int>> &dp)
    {
        if(idx>=nums.size())
        {
            s.insert(sum);
            return 0;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int n_pick = helper(idx+1,sum,nums,dp);
        int pick = helper(idx+1,sum+nums[idx],nums,dp);
        return dp[idx][sum]=pick+n_pick;
    }
   
	vector<int> DistinctSum(vector<int>nums){
	    int n = nums.size();
	    int total =0;
	    for(int i =0 ; i<n ; i++)
	    {
	        total+=nums[i];
	    }
	    vector<vector<int>> dp(n,vector<int>(total+1,-1));
	    vector<int> ans;
	    helper(0,0,nums,dp);
	    for(auto it : s)
	    {
	        ans.push_back(it);
	    }
	    return ans;
	    
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends