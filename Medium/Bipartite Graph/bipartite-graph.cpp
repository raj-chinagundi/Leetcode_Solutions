//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int v,int curr_color,vector<int> &color,vector<int> adj[]){
        color[v]=curr_color;//parent ka color
        for(auto adjNode:adj[v]){
            if(color[adjNode]==-1){
                curr_color=!color[v];
                if(dfs(adjNode,curr_color,color,adj))return true;
            }
            else if(color[adjNode]==color[v])return true;
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj)==true)return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends