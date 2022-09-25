class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int l=0, ans=1;
        for(int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                l++;
                ans = max(ans,l);
            } else {
                l=0;
            }
        }
        return ans;        
    }
};