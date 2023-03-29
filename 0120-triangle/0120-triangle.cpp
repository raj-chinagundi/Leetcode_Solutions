class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n=triangle.size();
        if(i==n-1)return triangle[n-1][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down=triangle[i][j]+solve(i+1,j,triangle,dp);
        int diag=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(0,0,triangle,dp);
        return (n==1)?triangle[0][0]:dp[0][0];
    }
};