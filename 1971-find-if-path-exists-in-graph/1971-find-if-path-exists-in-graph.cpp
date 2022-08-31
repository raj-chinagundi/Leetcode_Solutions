class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> umap;
    for(auto x: edges){
        vector<int>temp = x;

        int u = temp[0];
        int v = temp[1];

        umap[u].push_back(v);
        umap[v].push_back(u);
    }
//     for(auto &x:mp){
//         cout<<x.first<<"->";
//         for(auto i:x.second){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        
//     }
    vector<int> vis(n+1,false);
    queue<int>q;
    vis[source]=true;
    q.push(source);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vector<int>temp=umap[u];
        for(int v:temp){
            if(vis[v]==false){
                vis[v]=true;
                q.push(v);
            }                    
        }
    }
    if(vis[destination]){
        return vis[destination];
    }
    return false;
    }
};