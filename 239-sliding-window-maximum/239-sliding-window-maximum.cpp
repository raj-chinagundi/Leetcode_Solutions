class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        vector<int> ans;
        deque<int> dq;
        while(j<nums.size()){
            while (dq.size() > 0 && dq.back() < nums[j]) {
                dq.pop_back();
            }   
            dq.push_back(nums[j]);
            if (j - i + 1 < k) {
                j++;
            }
            else if(j-i+1==k){
                int mx=dq.front();
                ans.push_back(mx);
                if (nums[i] == dq.front()) {
                    dq.pop_front();
                }
                i++;
                j++; 
            }
        }
        return ans;
    }
};