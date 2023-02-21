class Solution {
public:
    bool cycleDFS(int s,vector<int> adj[],vector<int> &vis,vector<int> &pVis){
        vis[s]=1;
        pVis[s]=1;
        
        for(auto n:adj[s]){
            if(!vis[n]){
                if(cycleDFS(n,adj,vis,pVis)) return true;
            }
            else if(pVis[n])return true;
        }
        
        pVis[s]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adj[V];
        vector<int> vis(V,0);
        vector<int> pVis(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
                if(cycleDFS(i,adj,vis,pVis)==false){
                    ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};