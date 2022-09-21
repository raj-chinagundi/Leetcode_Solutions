class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum=0;
        for(auto i:nums){
            if(i%2==0){
                sum+=i;
            }
        }
        for(auto i:queries){
            int add=i[0];
            int index=i[1];
            int n=nums[index];
            if(n%2==0 && add%2==0){
                sum+=add;
            }
            else if(n%2!=0 && add%2!=0){
                sum+=add+n;
            }
            else if(n%2==0 && add%2!=0){
                sum-=n;
            }
            nums[index]=nums[index]+add;
            ans.push_back(sum);
        }
        return ans;
    }
};