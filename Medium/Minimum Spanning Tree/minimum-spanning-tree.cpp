//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DisjointSet{
    public:
        vector<int> rank,parent;
    
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findP(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findP(parent[u]);//pcompress
        }
        
        void unionByRank(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            if(upu==upv)return;
            if(rank[upu]>rank[upv]){
                parent[upv]=upu;
            }
            else if(rank[upv]>rank[upu]){
                parent[upu]=upv;
            }
            else{
                parent[upu]=upv;
                rank[upv]++;
            }
        }
};
class Solution
{
	public:
	#define pipii pair<int,pair<int,int>>
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                int v=x[0];
                int wt=x[1];
                int node=i;
                
                pq.push({wt,{node,v}});
            }
        }
        int mst=0;
        while(!pq.empty()){
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            int wt=pq.top().first;
            pq.pop();
            
            if(ds.findP(u)!=ds.findP(v)){
                mst+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mst;
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