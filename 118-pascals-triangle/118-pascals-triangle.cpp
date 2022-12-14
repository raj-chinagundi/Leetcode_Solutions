class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,0);
            temp[0]=1;
            temp[temp.size()-1]=1;
            if(i>1){
                vector<int> prev=ans[i-1];
                for(int j=2;j<temp.size();j++){
                    temp[j-1]=prev[j-1]+prev[j-2];   
                }
            }
            ans.push_back(temp);
        }
        return ans;        
    }
};