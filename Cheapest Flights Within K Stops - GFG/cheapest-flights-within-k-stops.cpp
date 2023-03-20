//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    #define pipii pair<int,pair<int,int>>  
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        
        for(auto x:flights){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            
            adj[u].push_back({v,wt});
        }
        queue<pipii> pq;
        //{stops, {node, dist}}
        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!pq.empty()){
            auto it=pq.front();
            int node=it.second.first;
            int stops=it.first;
            int cost=it.second.second;
            pq.pop();
            
            if(stops>K)continue;
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                
                if(cost+wt<dist[v]){
                    dist[v]=cost+wt;
                    pq.push({stops+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends