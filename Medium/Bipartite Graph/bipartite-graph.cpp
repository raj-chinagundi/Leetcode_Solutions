//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int v,vector<int> &color,vector<int>adj[]){
        queue<pair<int,int>> q;
        q.push({v,0});
        while(!q.empty()){
            int node=q.front().first;
            int clr=q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(color[adjNode]==-1){
                    color[adjNode]=!clr;
                    q.push({adjNode,!clr});
                }
                else if(color[adjNode]==clr){
                    return true;
                }
            }
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(bfs(i,color,adj)==true)return false;
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