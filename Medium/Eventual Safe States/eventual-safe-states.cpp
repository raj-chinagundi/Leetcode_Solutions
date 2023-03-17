//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> radj[V];
        vector<int> indegree(V,0);
		for (int i = 0; i < V; i++) {
			// i -> it (to) // it -> i
			for (auto it : adj[i]) {
    			radj[it].push_back(i);
    			indegree[i]++;
			}
		}
		queue<int> q;
		for(int i=0;i<V;i++){
		    if(indegree[i]==0)q.push(i);
		}
		vector<int> ans;
		while(!q.empty()){
		    int node=q.front();
		    q.pop();
		    ans.push_back(node);
		    for(auto adjNode:radj[node]){
		        indegree[adjNode]--;
		        if(indegree[adjNode]==0){
		            q.push(adjNode);
		        }
		    }
		}
		sort(ans.begin(),ans.end());
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