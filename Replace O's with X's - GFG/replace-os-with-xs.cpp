//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> mat){
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     vis[i][j]=1;

    // }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(mat[i][j] == 'O') {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            int dr[]={-1,0,+1,0};
            int dc[]={0,+1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    ans[i][j]='O';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends