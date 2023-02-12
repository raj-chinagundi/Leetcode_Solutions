class Solution {
public:
    int ways(int n){
        // if(n<=2)return n;
        // if(dp[n]!=-1)return dp[n];
        // int one=ways(n-1,dp);
        // int two=ways(n-2,dp);
        // return dp[n]=one+two;
        /*
        dp[0]=0;
        dp[1]=1;
        if(n>=2){
            dp[2]=2;
            for(int i=3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }            
        }
        */
        int prev2=1;
        int prev=2;
        if(n>1){
            for(int i=3;i<=n;i++){
                int curri=prev2+prev;
                prev2=prev;
                prev=curri;
            }  
        }
        return (n < 2) ? 1 : prev;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1);
        return ways(n);
    }
};