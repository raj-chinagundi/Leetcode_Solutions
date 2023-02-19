class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||grid[i][j]==0)return;
        
        vis[i][j]=1;
        
        dfs(i+1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j-1,vis,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int k=0;k<m;k++){
            if(!vis[0][k] && grid[0][k]==1){
                dfs(0,k,vis,grid);
            }
            if(!vis[n-1][k] && grid[n-1][k]==1){
                dfs(n-1,k,vis,grid);
            }
        }
        for(int k=0;k<n;k++){
            if(!vis[k][0] && grid[k][0]==1){
                dfs(k,0,vis,grid);
            }
            if(!vis[k][m-1] && grid[k][m-1]==1){
                dfs(k,m-1,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    grid[i][j]=0;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};