class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> temp;
        unordered_map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            if(mp[arr2[i]]){
                while(mp[arr2[i]]>0){
                    ans.push_back(arr2[i]);
                    mp[arr2[i]]-=1;
                }                
            }
        }
        for(auto i:mp){
            int k=i.first;
            while(mp[k]){
                temp.push_back(k);
                mp[k]--;
            } 
        }
        sort(temp.begin(),temp.end());
        for(auto i:temp){
            ans.push_back(i);
        }
        return ans;
    }
};