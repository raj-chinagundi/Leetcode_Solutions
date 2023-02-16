class Solution {
public:
    
    void dfs(int s,vector<int> &vis,vector<int> adj[]){
        vis[s]=1;
        for(auto x:adj[s]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<int> adj[isConnected.size()+1];
        vector<int> vis(isConnected.size()+1,0);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        for(int i=1;i<=isConnected.size();i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};