//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            
            adj[u].push_back({v,wt});
        }
        vector<int> dist(N,1e9);
        queue<pair<int,int>> q;
        //dist,node
        q.push({0,0});
        dist[0]=0;
        
        while(!q.empty()){
            int node=q.front().second;
            int dis=q.front().first;
            q.pop();
            
            for(auto it:adj[node]){
                int adjN=it.first;
                int wt=it.second;
                
                if(dis+wt<dist[adjN]){
                    dist[adjN]=dis+wt;
                    q.push({dist[adjN],adjN});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends