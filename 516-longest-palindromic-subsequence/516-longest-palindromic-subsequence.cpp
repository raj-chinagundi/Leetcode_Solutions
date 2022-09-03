class Solution {
public:
    int dp[1000+1][1000+1];
    int LCS(string &x, string &y,int n,int m){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(0+dp[i-1][j],0+dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string act=s;
        reverse(s.begin(),s.end());
        string rev=s;
        int n=act.length();
        int m=rev.length();
        return LCS(act,rev,n,m);
    }
};