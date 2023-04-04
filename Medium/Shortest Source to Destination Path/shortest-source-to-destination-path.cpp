//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[X][Y]==0 or A[0][0]==0)return -1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        A[0][0]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=dr[i]+row;
                int ncol=dc[i]+col;
                if(nrow>=0 and ncol>=0 and nrow<N and ncol<M and A[nrow][ncol]==1){
                    A[nrow][ncol]=A[row][col]+1;
                    if(nrow==X and ncol==Y)return A[row][col];
                    q.push({nrow,ncol});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends