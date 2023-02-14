class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();

        int prev=nums[0];
        int prev2=0;//negative index wala element
        for(int i=1;i<n;i++){
            int r=nums[i];
            if(i>1)r+=prev2;
            int nr=0+prev; 
            int curi=max(r,nr);
            prev2=prev;
            prev=curi;
        }

        return prev;
    }
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        int finclude=solve(temp1);
        int linclude=solve(temp2);
        return max(finclude,linclude);
    }
};