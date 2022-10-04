class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        for(auto x:strs){
            string temp=x;
            sort(x.begin(),x.end());
            umap[x].push_back(temp);
        }
        for(auto i:umap){
            ans.push_back(i.second);
        }
        return ans;
    }
};