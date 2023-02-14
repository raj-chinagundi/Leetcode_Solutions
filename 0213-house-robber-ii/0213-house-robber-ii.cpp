class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>&dp){
        if(ind==0)return nums[ind];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int r=nums[ind]+solve(ind-2,nums,dp);
        int nr=0+solve(ind-1,nums,dp);
        return dp[ind]=max(r,nr);
    }
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        int finclude=solve(n-2,temp1,dp1);
        int linclude=solve(n-2,temp2,dp2);
        return max(finclude,linclude);
    }
};