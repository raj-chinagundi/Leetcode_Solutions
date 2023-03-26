class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        //steps dist node
        vector<pair<int,int>> adj[n];
;       for(auto x:flights){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            
            adj[u].push_back({v,wt});
        }
        pq.push({0,{0,src}});
        vector<int> dist(n,1e9);
        while(!pq.empty()){
            auto it=pq.top();
            int steps=it.first;
            int cost=it.second.first;
            int node=it.second.second;
            pq.pop();
            
            if(steps>k)continue;
            
            for(auto x:adj[node]){
                int adjN=x.first;
                int wt=x.second;
                if(cost+wt<dist[adjN]){
                    dist[adjN]=cost+wt;
                    pq.push({steps+1,{dist[adjN],adjN}});
                }
            }
        }
        return (dist[dst]==1e9)?-1:dist[dst];
    }
};