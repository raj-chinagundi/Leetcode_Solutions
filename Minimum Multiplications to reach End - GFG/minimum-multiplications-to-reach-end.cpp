//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
#define pii pair<int,int>
const int mod=1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int> dist(1e5,1e9);
        dist[start]=0;
        //steps,node
        pq.push({0,start});
        while(!pq.empty()){
            int steps=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(node==end){
                return steps;
            }
            for(auto x:arr){
                int d=(node*x)%mod;
                if(steps+1<dist[d]){
                    dist[d]=steps+1;
                    pq.push({dist[d],d});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends