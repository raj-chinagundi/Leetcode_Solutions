class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int> umap;
        for(auto i:s){
            umap[i]++;
        }
        for(auto x:order){
            if(umap.find(x)!=umap.end()){
                int count=umap[x];
                string t(count,x);
                ans+=t;
                umap.erase(x);
            }
        }
        for(auto i:umap){
            string add(i.second,i.first);
            ans+=add;
        }
        return ans;
    }
};