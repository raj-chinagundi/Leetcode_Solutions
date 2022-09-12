class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums){
            if(i%2==0){
                mp[i]++;
            }
        }
        int mx=INT_MIN;
        for(auto i:mp){
            if(i.second>mx ){
                mx=i.second;
            }
        }
        int count=0;
        for(auto i:mp){
            cout<<i.first<<"->"<<i.second<<endl;
            if(i.second==mx){
                count=i.first;
                break;
            }
        }
        return mp.empty()?-1:count;
    }
};