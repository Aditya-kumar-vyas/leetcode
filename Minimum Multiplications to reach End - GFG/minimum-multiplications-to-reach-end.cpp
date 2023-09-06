//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
          
          queue<pair<int,int>> q;
          vector<int> dis (100000,INT_MAX);
          int steps=0;
          q.push({steps,start});
          dis[start]=0;
          while(!q.empty())
          {
              int node = q.front().second;
              int st = q.front().first;
              q.pop();
              for(auto it : arr)
              {
                  int n_node = (node*it)%100000;
                  if(st+1<dis[n_node])
                  {
                      dis[n_node]=st+1;
                      q.push({st+1,n_node});
                  }
              }
          }
          if(dis[end]==INT_MAX)
          {
              return -1;
          }
          return dis[end];
          
          
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends