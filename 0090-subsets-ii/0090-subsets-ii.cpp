class Solution {
public:
    void solve(int ind,vector<int> &ds,vector<int>&arr,vector<vector<int>> & ans){
        ans.push_back(ds);
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            solve(i+1,ds,arr,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(0,v,nums,ans);
        return ans;
    }
};