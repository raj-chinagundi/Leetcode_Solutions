class Solution {
public:
    int ways(int n,vector<int> &dp){
        if(n<=2)return n;
        if(dp[n]!=-1)return dp[n];
        int one=ways(n-1,dp);
        int two=ways(n-2,dp);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ways(n,dp);
    }
};