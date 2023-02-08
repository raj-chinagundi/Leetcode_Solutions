class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0;
        int mx_sum=nums[0];
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            csum=max(csum,nums[i]);
            mx_sum=max(csum,mx_sum);
        }
        return mx_sum;
    }
};