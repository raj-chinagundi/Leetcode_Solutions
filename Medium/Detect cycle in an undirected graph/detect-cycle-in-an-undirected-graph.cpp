//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int s,vector<int> &vis,vector<int> adj[]){
        //node,parent
        queue<pair<int,int>>q;
        q.push({s,-1});
        vis[s]=1;
        while(!q.empty()){
            int p=q.front().second;
            int node=q.front().first;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    //S is parent now
                    q.push({it,node});
                    vis[it]=1;
                }
                //adj node is visited and is not a parent
                else if(it!=p){
                    return true;
                }
            }            
        }
        return false;

    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends