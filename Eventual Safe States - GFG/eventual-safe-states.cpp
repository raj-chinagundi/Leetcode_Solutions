//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool cycleDFS(int s,vector<int> adj[],vector<int> &vis,vector<int> &pVis,vector<int> &safeNode){
        vis[s]=1;
        pVis[s]=1;
        safeNode[s]=0;
        for(auto n:adj[s]){
            if(!vis[n]){
                if(cycleDFS(n,adj,vis,pVis,safeNode)) return true;
            }
            else if(pVis[n])return true;
        }
        safeNode[s]=1;
        pVis[s]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        vector<int> pVis(V,0);
        vector<int> safeNode(V,0);
        for(int i=0;i<V;i++){
                if(!vis[i]){
                    cycleDFS(i,adj,vis,pVis,safeNode);
            }
        }
        for(int i=0;i<safeNode.size();i++){
            if(safeNode[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends