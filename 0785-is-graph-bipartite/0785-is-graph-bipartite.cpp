class Solution {
public:
    bool dfs(int p,int pcolor,vector<int> &vis,vector<int> &color,vector<int> adj[]){
        vis[p]=1;
        for(auto it:adj[p]){
            if(!vis[it]){
                color[it]=!pcolor;
                if(dfs(it,color[it],vis,color,adj)) return true;
            }
            else if(color[it]==color[p])return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        vector<int> color(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,0,vis,color,adj))return false;
            }
        }
        return true;
    }
};