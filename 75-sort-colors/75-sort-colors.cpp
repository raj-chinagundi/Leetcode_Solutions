class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cz=0,co=0,ct=0;
        for(auto i:nums){
            if(i==0){
                cz++;
            }
            else if(i==1){
                co++;
            }
            else{
                ct++;
            }
        }
        int i=0;
        while(cz>0){
            nums[i]=0;
            i++;
            cz--;
        }
        while(co>0){
            nums[i]=1;
            i++;
            co--;
        }
        while(ct>0){
            nums[i]=2;
            i++;
            ct--;
        }
    }
};