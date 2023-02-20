class Solution {
public:
    int bs(int s,int e,vector<int>& nums, int target){
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target)return m;
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find smallest indx
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right])left=mid+1;
            else right=mid;
        }
        int s=0;
        int e=nums.size()-1;
        if(nums[right]==target)return right;
        int a=bs(right,e,nums,target);
        int b=bs(s,right,nums,target);
        if(a==-1 && b==-1)return -1;
        return (a==-1)?b:a;
    }
};