class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/3)s.insert(nums[i]);
        }
        vector<int> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};