class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pVis,vector<int> adj[]){
        vis[node]=1;
        pVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pVis,adj))return true;
            }
            else if(pVis[it]){
                return true;
            }
        }
        pVis[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(n,0);
        vector<int> pVis(n,0);
        vector<int> ans; 
        for(int i=0;i<n;i++){
           if(dfs(i,vis,pVis,adj)==false)ans.push_back(i);
        }
        return ans;
    }
};