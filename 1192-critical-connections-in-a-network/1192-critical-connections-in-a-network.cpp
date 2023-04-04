class Solution {
public:
    int timer=0;
    
    void dfs(int node,int parent,vector<int>&vis,vector<int> adj[],int tin[],int low[],vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,tin,low,bridges);
                //update low it values
                low[node]=min(low[node],low[it]);
                //can there be a bridge btw node and it
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};