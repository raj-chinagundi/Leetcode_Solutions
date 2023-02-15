class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pii> maxh;
        for(auto i:arr){
            maxh.push({abs(x-i),i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()>0){
            pii p=maxh.top();
            ans.push_back(p.second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};