class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> rowmark(m+1,0);
        vector<int> colmark(n+1,0);
        //marking row and column where zero exist
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowmark[i]=1;
                    colmark[j]=1;
                }
            }
        }
        for(auto i:colmark){
            cout<<i<<" ";
        }
        //setup matrix rows a zero
        for(int i=0;i<m;i++){
            if(rowmark[i]==1){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //setup matrix columns a zero
        for(int i=0;i<n;i++){
            if(colmark[i]==1){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
};