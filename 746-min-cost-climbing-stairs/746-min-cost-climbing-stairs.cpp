class Solution {
public:
    int fcost=0;
    int solve(int n,vector<int>& cost,vector<int> &dp){
        dp[0]=cost[0];
        dp[1]=cost[1];
        // if(dp[n]!=-1){
        //     return dp[n];
        // }
        for(int i=2;i<=n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};