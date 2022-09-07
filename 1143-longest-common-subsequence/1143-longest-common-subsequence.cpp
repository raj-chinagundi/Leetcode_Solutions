class Solution {
public:
    int t[1000+1][1000+1];
    int LCS(string &x,string &y,int n,int m){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                t[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(0+t[i-1][j],0+t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int longestCommonSubsequence(string text1, string text2){
        int a=text1.length();
        int b=text2.length();
        return LCS(text1,text2,a,b);
    }
};