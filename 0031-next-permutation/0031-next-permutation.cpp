class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        int n=nums.size()-1;
        for(int i=n;i>0;i--){
            if(nums[i]>nums[i-1]){
                bp=i;
                break;
            }
        }
        if(bp==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int mn=INT_MAX;
            int to_swap=nums[bp-1];
            for(int i=bp;i<=n;i++){
                if(nums[i]-to_swap>0 && nums[i]-to_swap<mn){
                    swap(nums[i],nums[bp-1]);
                }
            }
            sort(nums.begin()+bp,nums.end());
        }
    }
};