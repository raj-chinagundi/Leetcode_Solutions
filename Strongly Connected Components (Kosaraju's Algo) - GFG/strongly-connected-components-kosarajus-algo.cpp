//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void toposort(int node,stack<int>&st,vector<int> &vis,vector<vector<int>>& adj){
	    vis[node]=1;
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            toposort(x,st,vis,adj);
	        }
	    }
	    st.push(node);
	}
	void dfs(int node,stack<int>&st,vector<int> &vis,vector<vector<int>>& r_adj){
	    vis[node]=1;
	    for(auto x:r_adj[node]){
	        if(!vis[x]){
	            dfs(x,st,vis,r_adj);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(i,st,vis,adj);
            }
        }
        vector<vector<int>> r_adj(V);
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                r_adj[x].push_back(i);
            }
        }
        int count=0;
        vector<int> vis_r(V,0);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis_r[node]){
                count++;
                dfs(node,st,vis_r,r_adj);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends