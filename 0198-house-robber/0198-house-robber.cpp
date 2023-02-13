class Solution {
public:
    // int solve(int ind,vector<int> &nums,vector<int> &dp){
    //     if(ind==0)return nums[ind];
    //     if(ind<0)return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int loot=nums[ind]+solve(ind-2,nums,dp);
    //     int noloot=0+solve(ind-1,nums,dp);
    //     return dp[ind]=max(loot,noloot);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int prev=nums[0];
        int prev2=0;//negative indx
        for(int i=1;i<n;i++){
            int loot=nums[i];
            if(i>1)loot+=prev2;
            int noloot=0+prev;
            int curri=max(loot,noloot);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};