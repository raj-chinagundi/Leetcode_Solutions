class Solution {
public:
    #define pii pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,1e9);
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans= 0;
        for(int i=1;i<dist.size();i++){
            ans=max(ans,dist[i]);
        }
        return (ans==1e9)?-1:ans;
    }
};