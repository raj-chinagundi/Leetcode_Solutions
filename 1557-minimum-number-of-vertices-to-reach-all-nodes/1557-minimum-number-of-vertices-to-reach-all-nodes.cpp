class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<int> ans;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0 && vis[i]==0){
                dfs(i,vis,adj);
                ans.push_back(i);
            }
        }
        return ans;
    }
};