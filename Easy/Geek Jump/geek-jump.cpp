//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int n,vector<int>& height){
        vector<int> dp(n,0);
        int prev=0;
        int prev2=0;
        for(int i=1;i<n;i++){
            int one=abs(height[i]-height[i-1])+prev;
            int two=1e9;
            if(i>1){
                two=abs(height[i]-height[i-2])+prev2;
            }
            // cout<<one<<" "<<two<<endl;
            int curri=min(one,two);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return f(n,height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends