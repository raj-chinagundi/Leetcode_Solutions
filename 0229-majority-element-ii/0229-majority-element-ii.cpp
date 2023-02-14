class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=INT_MIN;
        int n2=INT_MIN;
        int count1=0;
        int count2=0;
        for(auto x:nums){
            if(x==n1)count1++;
            else if(x==n2)count2++;
            else if(count1==0){
                n1=x;
                count1=1;
            }
            else if(count2==0){
                n2=x;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c1=0;int c2=0;
        for(auto x:nums){
            if(x==n1)c1++;
            else if(x==n2)c2++;
        }
        vector<int> v;
        if(c1>nums.size()/3)v.push_back(n1);
        if(c2>nums.size()/3)v.push_back(n2);
        return v;
    }
};