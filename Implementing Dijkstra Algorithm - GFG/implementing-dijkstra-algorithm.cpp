//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    #define pii pair<int,int> 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<pii> adj2[V];
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                int v=x[0];
                int wt=x[1];
                adj2[i].push_back({v,wt});               
            }
        }
        vector<int> dist(V,1e9);
        set<pii> st;
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
            auto it=*st.begin();
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto it:adj2[node]){
                int v=it.first;
                int wt=it.second;
                if(dis+wt<dist[v]){
                    if(dist[v]!=1e9){
                        st.erase({dist[v],v});
                    }
                    dist[v]=dis+wt;
                    st.insert({dist[v],v});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends