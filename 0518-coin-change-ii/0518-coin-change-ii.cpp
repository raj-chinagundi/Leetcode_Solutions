class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
        //base case
        int bp=0;
        if(i==0){
            if(amount%coins[0]==0)return 1;
            return 0;
        }
        if(amount==0)return 1;
        
        if(dp[i][amount]!=-1)return dp[i][amount];
        //pick but dont move the indx
        int pick1=0;
        if(coins[i]<=amount){
            pick1=solve(i,amount-coins[i],coins,dp);
        }
        int notpick=solve(i-1,amount,coins,dp);
        return dp[i][amount]=pick1+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};