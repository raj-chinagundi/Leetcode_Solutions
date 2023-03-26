//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(1e5,1e9);
        dist[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        
        while(!pq.empty()){
            int node=pq.top().second;
            int steps=pq.top().first;
            pq.pop();
            
            if(node==end){
                return steps;
            }
            
            for(auto it:arr){
                int num=(node*it)%mod;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    pq.push({dist[num],num});
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