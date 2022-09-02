class Solution {
public:
    int dp[1000+1][1000+1];
    int LCS(string &s1,string& s2,int n,int m){
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
               if (i == 0 || j == 0) {
                   dp[i][j] = 0;
               } 
            }
        }
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(0 + dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2){
        string s1=text1;
        string s2=text2;
        int n=s1.length();
        int m=s2.length();
        return LCS(s1,s2,n,m);
    }
};