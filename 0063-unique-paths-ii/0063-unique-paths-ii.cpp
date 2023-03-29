class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(i>=0 and j>=0 and obstacleGrid[i][j]==1)return 0;//valid cell and obstacle
        
        if(i==0 and j==0)return 1;
        
        if(i<0 or j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=solve(i-1,j,obstacleGrid,dp);
        int left=solve(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // //edge cases
        if(obstacleGrid[n-1][m-1]==1 or obstacleGrid[0][0]==1)return 0;
        
        if(n==1 and m==1)return 1;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(n-1,m-1,obstacleGrid,dp);
        return dp[n-1][m-1];
    }
};