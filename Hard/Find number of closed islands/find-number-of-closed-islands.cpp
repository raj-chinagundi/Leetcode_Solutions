//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        if (N <= 2 || M <= 2) {
            return 0; // cant contain any island
        }
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(N,vector<int>(M,0));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if((i==0 || j==0 || i==N-1 || j==M-1) && matrix[i][j]==1 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0 && newc>=0 && newr<N && newc<M && matrix[newr][newc]==1 &&vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
        
        int count=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j]==1 && vis[i][j]==0){
                   count++;    
                   queue<pair<int,int>>q;
                   q.push({i,j});
                   vis[i][j]=1;
                   while(!q.empty()){
                       int r=q.front().first;
                       int c=q.front().second;
                       q.pop();
                        for(int i=0;i<4;i++){
                            int newr=r+dr[i];
                            int newc=c+dc[i];
                            if(newr>=0 && newc>=0 && newr<N && newc<M && matrix[newr][newc]==1 &&vis[newr][newc]==0){
                                vis[newr][newc]=1;
                                q.push({newr,newc});
                            }
                        }
                   }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends