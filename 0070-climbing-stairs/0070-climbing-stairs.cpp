class Solution {
public:
    int ways(int n,vector<int> &dp){
        // if(n<=2)return n;
        dp[0]=0;
        dp[1]=1;
        if(n>=2){
            dp[2]=2;
            for(int i=3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }            
        }
        return dp[n];
        // if(dp[n]!=-1)return dp[n];
        // int one=ways(n-1,dp);
        // int two=ways(n-2,dp);
        // return dp[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return ways(n,dp);
    }
};