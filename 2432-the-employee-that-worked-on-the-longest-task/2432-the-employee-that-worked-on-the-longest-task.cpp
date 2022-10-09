class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int mx=logs[0][1];
        int ans=logs[0][0];
        pair<int,int> p1;
        p1.first=ans;
        p1.second=mx;
        for(int i=1;i<logs.size();i++){
            int curr_time_taken=logs[i][1]-logs[i-1][1];
            if(curr_time_taken>mx){
                mx=curr_time_taken;
                p1.first=logs[i][0];
                p1.second=mx;
            }
            if(curr_time_taken==mx && p1.first>logs[i][0]){
                p1.first=logs[i][0];
                p1.second=mx;
            }
        }
        ans=p1.first;
        return ans;
    }
};