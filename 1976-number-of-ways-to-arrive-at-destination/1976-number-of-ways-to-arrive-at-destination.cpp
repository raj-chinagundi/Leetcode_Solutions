class Solution {
public:
    #define ll long long
    #define pii pair<ll,ll>
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pii> adj[n];
        ll mod=(ll)1e9+7;
        ll inf=(ll)1e15;
        vector<ll> dist(n,inf),ways(n,0);
        ways[0]=1;// way to reach src point
        dist[0]=0;
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll node=pq.top().second;
            ll dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                ll v=it.first;
                ll wt=it.second;
                
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    ways[v]=ways[node]%mod;
                    pq.push({dist[v],v});
                }
                
                else if(dis+wt==dist[v]){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }
        return (dist[n-1]==1e15)?-1:ways[n-1]%mod;
    }
};