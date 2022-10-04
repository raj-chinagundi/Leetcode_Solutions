class Solution {
public:
    int fcost=0;
    int solve(int n,vector<int>& cost,vector<int> &dp){
        if(n==0)return cost[0];
        if(n==1)return cost[1];
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=cost[n]+min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};