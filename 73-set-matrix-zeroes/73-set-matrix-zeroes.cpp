class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();  
        //3step solution:
        //bool var
        bool rowcheck=false;
        bool colcheck=false;
        //check col and row zero if any item is zero set true
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                colcheck=true;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                rowcheck=true;
                break;
            }
        }
    //check inner matrix mark row zero or column zero as zero if any element found
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        //now check for row and col booleans
        if(colcheck){
             for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }           
        }
        if(rowcheck){
             for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }           
        }
    }
};