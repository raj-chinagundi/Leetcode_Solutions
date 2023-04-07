//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int n,int *arr){
    vector<int> dp(n,-1);	    
    int prev2=arr[0];
    int prev=arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0+ prev;
        
        int curri= max(pick, nonPick);
        prev2=prev;
        prev=curri;
    }
    
    
    return prev;
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    return f(n,arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends