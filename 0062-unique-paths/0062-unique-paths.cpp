class Solution {
public:
//     int f(int i,int j,int m,int n){
//         if(i==0 and j==0)return 1;//destination
        
//         if(i>=m or j>=n or i<0 or j<0)return 0;//invalid path
        
//         int up=f(i-1,j,m,n);
//         int left=f(i,j-1,m,n);
        
//         return up+left;
//     }
    int uniquePaths(int m, int n) {
        // return f(m-1,n-1,m,n);
        vector<vector<int>> dp (m , vector<int>(n,0));
          for(int i=0; i<m ;i++){
              for(int j=0; j<n; j++){

                  //base condition
                  if(i==0 && j==0){
                      dp[i][j]=1;
                      continue;
                  }

                  int up=0;
                  int left = 0;

                  if(i>0) 
                    up = dp[i-1][j];
                  if(j>0)
                    left = dp[i][j-1];

                  dp[i][j] = up+left;
              }
          }

          return dp[m-1][n-1];
    }
};