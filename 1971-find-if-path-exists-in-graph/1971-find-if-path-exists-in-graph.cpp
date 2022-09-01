class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //graph bnao pehle
        unordered_map<int,vector<int>> umap;
        for(auto x:edges){
            vector<int> temp=x;
            int u=temp[0];
            int v=temp[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        vector<bool> vis(n+1,false);
        queue<int>q;
        vis[source]=true;
        q.push(source);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            //graph mai check kro fr
            for(int v:umap[u]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push(v);
                }
            }
            if(vis[destination])
                return vis[destination];
        }
        return vis[destination];
    }
};