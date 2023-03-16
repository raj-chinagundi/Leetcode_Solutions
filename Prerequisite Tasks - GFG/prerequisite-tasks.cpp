//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[N];
	    vector<int> in(N, 0);
	    queue<int> q;
	    int ct = 0;
	    for(auto it: pre){
	        adj[it.second].push_back(it.first);
	        in[it.first]++;
	    }
	    
	    for(int i=0; i<N; i++){
	        if(in[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        auto n = q.front();
	        q.pop();
	        ct+=1;
	        for(auto it: adj[n]){
	            in[it]--;
	            if(in[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return (ct==N)?1:0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends