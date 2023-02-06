class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        stack<int> s;
        vector<int> v;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && nums2[i]>=s.top()){
                s.pop();
            }
            if(s.empty())v.push_back(-1);
            else v.push_back(s.top());
            s.push(nums2[i]);
        }
        int n=nums2.size()-1;
        reverse(v.begin(),v.end());
        vector<int> nxtG;
        for(auto x:nums1){
            int ind=mp[x];
            nxtG.push_back(v[ind]);
        }
        return nxtG;
    }
};