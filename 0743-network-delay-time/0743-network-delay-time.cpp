class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto x:times){
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            
            adj[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                
                if(dis+wt<dist[v]){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int answer = 0;
        for(int i = 1 ; i < dist.size() ; ++i){    
            answer = max(answer , dist[i]);    // Distance of farthest node would be our answer.
        }
        if(answer == 1e9){      // Means we have missed some node.
            return -1;
        }
        return answer;
    }
};