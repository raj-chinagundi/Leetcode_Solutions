class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //check if nothing is filled
                if(board[i][j]=='.'){
                    
                    for(char c='1';c<='9';c++){
                        //check if that character can be filled
                        if(isValid(i,j,board,c)){
                            board[i][j]=c;
                            //valid solution found
                            if(solve(board)==true)return true;
                            //remove that character if it wasnt right solution backtrack
                            else board[i][j]='.';
                        }   
                    }
                    //return false for invalid solution
                    return false;   
                }
            }
        }
        //everything filled up return true
        return true;
    }
    
    bool isValid(int row,int col,vector<vector<char>>& board,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
};