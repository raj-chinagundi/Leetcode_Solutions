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
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int> prev(n,0);
        for(int j=m-1;j>=0;j--){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n,0);
            for(int j=i; j>=0; j--){

                int down = triangle[i][j]+prev[j];
                int diagonal = triangle[i][j]+prev[j+1];

                curr[j] = min(down, diagonal);
            }
            prev=curr;
        }
        return prev[0];
    }
};