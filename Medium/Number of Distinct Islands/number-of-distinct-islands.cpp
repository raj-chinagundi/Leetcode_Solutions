//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,int sr,int sc,vector<pair<int,int>>&src,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
      if(i<0 || j<0 || i>=n ||j>=m ||grid[i][j]==0)return;
      src.push_back({i-sr,j-sc});
      grid[i][j]=0;
      
      dfs(i+1,j,sr,sc,src,grid);
      dfs(i,j+1,sr,sc,src,grid);
      dfs(i-1,j,sr,sc,src,grid);
      dfs(i,j-1,sr,sc,src,grid);
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // code here
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>> src;
                if(grid[i][j]==1){
                    dfs(i,j,i,j,src,grid);
                    st.insert(src);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends