//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int n,int k,vector<int>& height){
      vector<int> dp(n,-1);
      dp[0]=0;
      
      for(int j=1;j<n;j++){
          int mncost=1e9;
          for(int i=1;i<=k;i++){
              if(j-i>=0){
                int kthcost=abs(height[j]-height[j-i])+dp[j-i];
                mncost=min(kthcost,mncost);
              }
          }
          dp[j]=mncost;
      }

      return dp[n-1];
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return f(n,k,height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends