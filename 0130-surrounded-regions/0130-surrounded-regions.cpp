class Solution {
public:
    void dfs(int i,int j, vector<vector<int>> &vis,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||board[i][j]=='X')return;
        
        vis[i][j]=1;
        
        dfs(i+1,j,vis,board);
        dfs(i,j+1,vis,board);
        dfs(i-1,j,vis,board);
        dfs(i,j-1,vis,board);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int k=0;k<m;k++){
            if(!vis[0][k] && board[0][k]=='O'){
                dfs(0,k,vis,board);
            }
            if(!vis[n-1][k] && board[n-1][k]=='O'){
                dfs(n-1,k,vis,board);
            }
        }
        for(int k=0;k<n;k++){
            if(!vis[k][0] && board[k][0]=='O'){
                dfs(k,0,vis,board);
            }
            if(!vis[k][m-1] && board[k][m-1]=='O'){
                dfs(k,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};