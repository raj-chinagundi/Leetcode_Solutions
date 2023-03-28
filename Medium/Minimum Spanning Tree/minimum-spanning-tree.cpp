//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	#define pipii pair<int,pair<int,int>>
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //dist,node,parent
        vector<int> vis(V,0);
        vector<pair<int,int>> mst;
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        pq.push({0,{0,-1}});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second.first;
            int parent=it.second.second;
            int pwt=it.first;
            pq.pop();
            
            if(vis[node]==1)continue;
            
            vis[node]=1;
            sum+=pwt;
            if(parent!=-1)mst.push_back({parent,node});
            for(auto x:adj[node]){
                int adjNode=x[0];
                int edwt=x[1];
                
                if(!vis[adjNode]){
                    pq.push({edwt,{adjNode,node}});
                }
            }
        }
        
        // for(auto x:mst){
        //     cout<<x.first<<" "<<x.second<<endl;
        //     cout<<endl;
        // }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends