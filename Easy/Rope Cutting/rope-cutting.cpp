//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    void solve(int s,int arr[], int n,vector<int> &ans){
        if(s==n-1){
            return;
        }
        if(arr[s]!=arr[s+1]){
            ans.push_back(n-s-1);
        }
        solve(s+1,arr,n,ans);
    }
        vector<int> RopeCutting(int arr[], int n)
    {
        // Complete the function
        sort(arr,arr+n);
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        vector<int> ans;
        solve(0,arr,n,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{   
    int T;
    cin>> T;
    while(T--)
    {
       	int n;
       	cin>>n;
       	int arr[n+1];
       	for(int i=0;i<n;i++)
       	   cin>>arr[i];
        
        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        
        
    }
  return 0;
}
// } Driver Code Ends