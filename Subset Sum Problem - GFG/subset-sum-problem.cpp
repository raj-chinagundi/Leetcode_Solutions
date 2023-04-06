//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int i,vector<int>arr, int target,vector<vector<int>> &dp){
        if(target==0)return true;
        if(i==0)return (arr[0]==target);
        
        if(dp[i][target]!=-1)return dp[i][target];
        
        bool not_take=solve(i-1,arr,target,dp);
        
        bool take=false;
        
        if(target>=arr[i]){
            take=solve(i-1,arr,target-arr[i],dp);
        }
        
        return dp[i][target]=(take||not_take);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        solve(n-1,arr,sum,dp);
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends