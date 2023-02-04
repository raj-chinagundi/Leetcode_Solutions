//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
        void stringsform(string S,string &ds, int freq[], set<string>&v){
            if(ds.size()==S.size()){
                v.insert(ds);
                return ;
            }
            for(int i=0; i<S.size(); i++){
                if(!freq[i]){
                    ds+=S[i];
                    freq[i]=1;
                    stringsform(S,ds,freq,v);
                    freq[i]=0;
                    ds.pop_back();
                }
            }
        }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string ds="";
		    set<string>v;
		    vector<string>ans;
		    int n=S.size();
		    int freq[n]={0};
		    for(int i=0; i<n; i++) freq[i]=0;
		    
		    stringsform(S,ds,freq,v);
		    for(auto it:v){
		        ans.push_back(it);
		    }
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