class Solution {
public:
    bool binSearch(int n,vector<int> &nums){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            cout<<nums[s]<<" "<<nums[m]<<" "<<nums[e]<<endl;
            if(n==nums[m]){
                return true;
            }
            else if(n>nums[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ncol=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][ncol-1]){
                cout<<matrix[i][0]<<" "<<matrix[i][ncol-1]<<endl;
                return binSearch(target,matrix[i]);
            }
        }
        return false;
    }
};