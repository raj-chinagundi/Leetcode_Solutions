class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int n=nums.size();
        while(s<=e){
            int m=s+(e-s)/2;
            int next=(m+1)%n;
            int prev=(m+n-1)%n;
            if(nums[s]<=nums[m] && nums[m]<=nums[e])return nums[s];
            if(nums[m]<=nums[prev] && nums[m]<=nums[next]){
                return nums[m];
            }
            if(nums[s]<=nums[m]){
                s=m+1;
            }
            else if(nums[e]>=nums[m]){
                e=m-1;
            }
        }
        return -1;
    }
};