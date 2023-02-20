class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                first=m;
                e=m-1;
            }
            else if(target<nums[m]){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        s=0;
        e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                last=m;
                s=m+1;
            }
            else if(target<nums[m]){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        vector<int> ans={first,last};
        return ans;
    }
};