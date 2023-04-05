class Solution {
public:
    void dfs(int node,int n,vector<int>&p,vector<int> adj[],vector<vector<int>> &ans){
        p.push_back(node);
        if(node==n-1){
            ans.push_back(p);
        }
        for(auto it:adj[node]){
            dfs(it,n,p,adj,ans);
        }
        p.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> p;
        vector<int> adj[n];
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        dfs(0,n,p,adj,ans);
        return ans;
    }
};