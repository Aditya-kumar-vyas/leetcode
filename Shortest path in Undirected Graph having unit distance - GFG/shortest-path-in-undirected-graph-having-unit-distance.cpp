//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
     vector<pair<int,int>> adj[n];
        for(int i =0 ; i<m ; i++)
        {
             adj[edges[i][0]].push_back({edges[i][1],1});
             adj[edges[i][1]].push_back({edges[i][0],1});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        // vector<int> parent(n+1);
        // for(int i =1 ; i<=n ; i++)
        // {
        //     parent[i]=i;
        // }
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int door = pq.top().first;
            pq.pop();
            for(auto it : adj[node])
            {
                 if(door+it.second<dis[it.first])
                 {
                     dis[it.first]=door+it.second;
                     pq.push({dis[it.first],it.first});
                     
                 }
            }
            
        }
        for(int i =0 ; i<n ; i++)
        {
             if(dis[i]==INT_MAX)
             {
                 dis[i]=-1;
             }
        }
        return dis;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends