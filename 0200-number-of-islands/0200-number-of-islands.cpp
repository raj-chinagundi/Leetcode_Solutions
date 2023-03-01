class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0')return;
        
        grid[i][j]='0';
        
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};