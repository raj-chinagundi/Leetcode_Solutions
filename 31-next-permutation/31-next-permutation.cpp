class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpt=-1;
        for(int i = nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                breakpt=i-1;
                break;
            }
        }
        if(breakpt<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[breakpt]){
                swap(nums[i],nums[breakpt]);
                reverse(nums.begin()+breakpt+1,nums.end());
                break;
            }            
        }

    }
};