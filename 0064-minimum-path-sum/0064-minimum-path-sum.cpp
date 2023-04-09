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
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    curr[j]=grid[i][j];
                    continue;
                }
                int up=grid[i][j];
                int left=grid[i][j];
                if(i>0)up+=prev[j];
                else up+=1e9;
                if(j>0)left+=curr[j-1];
                else left+=1e9;
                curr[j]=min(up,left);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};