//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(int ind,string &S,vector<string> &ans){
	    if(ind==S.size()){
	        ans.push_back(S);
	        return;
	    }
	    for(int i=ind;i<S.size();i++){
	        if(i>ind && S[i]==S[i-1])continue;
	        swap(S[ind],S[i]);
	        solve(ind+1,S,ans);
	        swap(S[ind],S[i]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    sort(S.begin(),S.end());
		    solve(0,S,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends