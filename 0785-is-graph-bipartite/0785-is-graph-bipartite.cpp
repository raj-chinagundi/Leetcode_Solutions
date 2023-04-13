class Solution {
public:
    bool dfs(int node,int color,vector<int> &pcolor,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                pcolor[it]=!color;
                if(dfs(it,!color,pcolor,vis,adj))return true;
            }
            else if(pcolor[it]==color){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        
        vector<int> vis(V,0);
        vector<int> pcolor(V,0);
        int initial_color=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,initial_color,pcolor,vis,adj)==true)return false;
            }
        }
        return true;
    }
};