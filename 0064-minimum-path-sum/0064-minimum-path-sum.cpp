class Solution {
public:
    int f(int i,int j,vector<vector<int>> &grid){
        if(i==0 and j==0)return grid[i][j];
        
        if(i<0 or j<0)return 1e9;
        
        int up=grid[i][j]+f(i-1,j,grid);
        int left=grid[i][j]+f(i,j-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // return f(m-1,n-1,grid);
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=grid[i][j];
                int left=grid[i][j];
                if(i>0)up+=dp[i-1][j];
                else up+=1e9;
                if(j>0)left+=dp[i][j-1];
                else left+=1e9;
                dp[i][j]=min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};