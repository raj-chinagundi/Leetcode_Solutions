class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            mp[u]++;
            mp[v]++;
        }
        for(auto it:mp){
            if(it.second>1){
                return it.first;
            }
        }
        return 0;
    }
};