class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int r=row;
        int c=col;
        while(row>-1 && col>-1){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=r;
        col=c;
        while(col>-1){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=r;
        col=c;
        while(row<n && col>-1){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //board of n size
        vector<string> board(n);
        //put n size strings in the board
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};