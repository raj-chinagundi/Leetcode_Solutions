class Solution {
public:
    const int mod=2e9;
    int f(int i,int j,vector<vector<int>>& obstacleGrid){
        int n=obstacleGrid[0].size();
        int m=obstacleGrid.size();
        if(i==0 and j==0)return 1;
        
        if(i<0 or j<0 or i>=m or j>=n or obstacleGrid[i][j]==1){
            return 0;
        }
        
        int up=f(i-1,j,obstacleGrid);
        int left=f(i,j-1,obstacleGrid);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //return f(m-1,n-1,obstacleGrid);
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                
                dp[i][j]=(up+left)%mod;
            }
        }
        return dp[m-1][n-1];
    }
};