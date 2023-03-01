class Solution {
public:
    void dfs(int s,vector<int> &vis,vector<int> adj[]){
        vis[s]=1;
        for(auto adjNode:adj[s]){
            if(!vis[adjNode]){
                dfs(adjNode,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size=isConnected.size();
        vector<int> adj[size+1];
        vector<int> vis(size+1,0);
        for(int i=0;i<size;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=size;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
        
    }
};