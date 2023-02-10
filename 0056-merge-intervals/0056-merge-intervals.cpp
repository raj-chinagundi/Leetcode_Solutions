class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInt=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempInt[1]){
                tempInt[1]=max(it[1],tempInt[1]);
            }
            else{
                ans.push_back(tempInt);
                tempInt=it;
            }
        }
        //last remaining interval
        ans.push_back(tempInt);
        return ans;
    }
};