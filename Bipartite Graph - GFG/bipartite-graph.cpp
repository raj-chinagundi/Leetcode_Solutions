//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkBFS(int s,vector<int> &color,vector<int> adj[]){
	    queue<int> q;
	    q.push(s);
	    color[s]=0;
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        for(auto i:adj[x]){
	            if(color[i]==-1){
	                color[i]=!color[x];
	                q.push(i);
	            }
	            else if(color[i]==color[x]){
	                return false;
	            }
	        }
	    }
	    return true;       
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
         vector<int> color(V,-1);
         for(int i=0;i<V;i++){
             if(color[i]==-1){
                 if(checkBFS(i,color,adj)==false) return false;
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