//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind,vector<int> &ds,vector<int> &arr,vector<int> &ans){
        if(ind==arr.size()){
            int sum=0;
            for(auto x:ds){
                sum+=x;
            }
            ans.push_back(sum);
            return;
        }
        ds.push_back(arr[ind]);
        solve(ind+1,ds,arr,ans);
        ds.pop_back();
        
        solve(ind+1,ds,arr,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        vector<int> ans;
        solve(0,v,arr,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends