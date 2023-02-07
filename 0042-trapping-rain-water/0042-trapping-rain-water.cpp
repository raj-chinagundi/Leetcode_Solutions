class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxl[n];
        maxl[0]=height[0];
        for(int i=1;i<n;i++){
            maxl[i]=max(maxl[i-1],height[i]);
        }
        int maxr[n];
        maxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],height[i]);
        }
        vector<int> w(n,0);
        for(int i=0;i<n;i++){
            int mn=min(maxl[i],maxr[i]);
            w[i]=mn-height[i];
        }
        int sum=0;
        for(auto x:w){
            sum+=x;
        }
        return sum;
    }
};