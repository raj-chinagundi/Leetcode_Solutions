//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int ind,int remaining_l,int price[],int wt[],vector<vector<int>> &dp){
          if(ind==0){
            //   if(remaining_l%wt[ind]==0){
            //       return price[0]*(remaining_l/wt[ind]);
            //   }
            return remaining_l*price[0];
            //   return 0;
          }
          if(dp[ind][remaining_l]!=-1)return dp[ind][remaining_l];
          int nottake=0+solve(ind-1,remaining_l,price,wt,dp);
          int take=0;
          if(wt[ind]<=remaining_l){
              take=price[ind]+solve(ind,remaining_l-wt[ind],price,wt,dp);
          }
          return dp[ind][remaining_l]=max(take,nottake);    
  }
    int cutRod(int price[], int n) {
        //code here
        int wt[n];
        for(int i=0;i<n;i++){
            wt[i]=i+1;
        }
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,wt,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends