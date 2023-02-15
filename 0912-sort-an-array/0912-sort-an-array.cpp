class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto x:nums){
            minh.push(x);
        }
        int i=0;
        while(minh.size()>0){
            nums[i]=minh.top();
            minh.pop();
            i++;
        }
        return nums;
    }
};