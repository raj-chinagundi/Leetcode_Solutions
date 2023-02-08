class Solution {
public:
    void sortColors(vector<int>& nums) {
        int czero=0,cone=0,ctwo=0;
        for(auto i:nums){
            if(i==0)czero++;
            if(i==1)cone++;
            if(i==2)ctwo++;
        }
        nums.clear();
        while(czero>0){
            nums.push_back(0);
            czero--;
        }
        while(cone>0){
            nums.push_back(1);
            cone--;
        }
        while(ctwo>0){
            nums.push_back(2);
            ctwo--;
        }
    }
};