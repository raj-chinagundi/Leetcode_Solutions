class Solution {
public:
    typedef pair<int,vector<int>> pii;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        vector<vector<int>> ans;
        priority_queue<pii> maxh;
        for(auto x:points){
            int d=(x[0]*x[0])+(x[1]*x[1]);
            maxh.push({d,{x[0],x[1]}});
            cout<<d<<" "<<x[0]<<" "<<x[1]<<endl;
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()>0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};