//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    long long mod = 1e9+7;
    
	public:
	int helper(int idx , long long sum1 , int arr[] , int sum,int n ,vector<vector<int>>&dp)
	{
	     if(sum1==sum)
	     {
	         return 1;
	     }
	     if(idx>=n)
	     {
	         return 0;
	     }
	     if(dp[idx][sum1]!=-1)
	     {
	         return dp[idx][sum1];
	     }
	     long long n_pick = helper(idx+1,(sum1),arr,sum,n,dp);
	     long long pick=0;
	     if(arr[idx]+sum1<=sum and arr[idx]!=0)
	     {
	          pick=helper(idx+1,(sum1+arr[idx]),arr,sum,n,dp);
	     }
	     return dp[idx][sum1]=(pick%mod+n_pick%mod)%mod;
	     
	     
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // n patha hai mujhe
        int cnt =0;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        for(int i =0 ; i<n ; i++)
        {
            if(arr[i]==0)
            {
                cnt++;
            }
        }
        long long ans =1;
        for(int i =0 ;i<cnt ; i++)
        {
             ans*=2;
        }
        if(cnt>0)
        {
           return helper(0,0,arr,sum,n,dp)*ans;  
        }
        return helper(0,0,arr,sum,n,dp);
        
        
       
        
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends