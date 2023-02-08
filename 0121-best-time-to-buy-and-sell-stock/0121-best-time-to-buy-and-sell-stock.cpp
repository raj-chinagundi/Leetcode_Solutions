class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> lsmall(n,0);
        lsmall[0]=prices[0];
        for(int i=1;i<n;i++){
            int ls=min(lsmall[i-1],prices[i]);
            lsmall[i]=ls;
        }
        vector<int> rlarge(n,0);
        rlarge[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            int rl=max(rlarge[i+1],prices[i]);
            rlarge[i]=rl;
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,rlarge[i]-lsmall[i]);            
        }
        return mx;
    }
};