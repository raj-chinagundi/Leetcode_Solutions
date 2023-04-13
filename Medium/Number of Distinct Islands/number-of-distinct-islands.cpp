//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &temp){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q; 
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        q.push({i,j});
        vis[i][j]=1;

        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            temp.push_back({row-i,col-j});
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>> temp;
                if(grid[i][j]==1 and vis[i][j]==0){
                    bfs(i,j,grid,vis,temp);
                    st.insert(temp);
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