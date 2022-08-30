class Solution {
public:
    bool subsetSum(vector<int>& nums,int target){
        int t[nums.size()+1][target+1];
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0){
                    t[i][j]=false;
                }
                if(j==0){
                    t[i][j]=true;
                }                
            }
        }
        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }
                else if(nums[i-1]>j){
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[nums.size()][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else {
            int k=sum/2;
            return subsetSum(nums,k);
        }
    }
};