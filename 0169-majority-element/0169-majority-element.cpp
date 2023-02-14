class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cand=0;
        for(auto i:nums){
            if(count==0){
                cand=i;
            }
            if(cand==i)count++;
            else count--;
        }
        return cand;
    }
};