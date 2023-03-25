class Solution {
public:
    bool dfs(int s,vector<int>&vis,vector<int>&pVis,vector<int> adj[]){
        vis[s]=1;
        pVis[s]=1;
        for(auto it:adj[s]){
            if(!vis[it]){
                if(dfs(it,vis,pVis,adj))return true;
            }
            else if(pVis[it])return true;
        }
        pVis[s]=0;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> pVis(n,0);
        for(int i=0;i<n;i++){
           if(dfs(i,vis,pVis,adj)==false)ans.push_back(i);
        }
        return ans;
    }
};