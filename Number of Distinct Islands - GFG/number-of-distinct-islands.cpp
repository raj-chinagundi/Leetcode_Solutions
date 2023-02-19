//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<pair<int,int>> &vec,vector<vector<int>> &visited,vector<vector<int>>& grid,int r0,int c0){
        visited[i][j]=1;
        vec.push_back({i-r0,j-c0});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,-1,0,+1};
        for(int k=0;k<4;k++){
            int row= i+delrow[k];
            int col=j+delcol[k];
            if(row>=0 and row<n and col>=0 and col<m and !visited[row][col] and grid[row][col]==1){
                dfs(row,col,vec,visited,grid,r0,c0);
            }
            }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vec,visited,grid,i,j);
                    st.insert(vec);
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