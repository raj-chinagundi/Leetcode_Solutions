class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        //invalid cases when Ldiag and R diag are out of bound
        if(j<0 or j>=n)return 1e9;
        //reached last row 
        if(i==n-1)return matrix[n-1][j];

        if(dp[i][j]!=-1)return dp[i][j];
        
        int ldiag=matrix[i][j]+solve(i+1,j-1,matrix,dp);
        int rdiag=matrix[i][j]+solve(i+1,j+1,matrix,dp);
        int down=matrix[i][j]+solve(i+1,j,matrix,dp);
        
        return dp[i][j]=min(min(ldiag,rdiag),down);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        //traverse through every element in first row and store the minimum;
        for(int j=0;j<n;j++){
            vector<vector<int>> dp(n,vector<int>(n,-1));
            solve(0,j,matrix,dp);
            int psum=dp[0][j];
            ans=min(ans,psum);
        }
        return (n==1)?matrix[0][0]:ans;
    }
};