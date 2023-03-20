//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        
        set<pair<int,int>> st;
        st.insert({0,1});
        
        vector<int> parent(n+1,0);
        for(int i=1;i<n+1;i++)parent[i]=i;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto adjN:adj[node]){
                int v=adjN.first;
                int wt=adjN.second;
                
                if(dis+wt<dist[v]){
                    if(dist[v]!=1e9){
                        st.erase({dist[v],v});
                    }
                    
                    dist[v]=dis+wt;
                    parent[v]=node;
                    st.insert({dist[v],v});
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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