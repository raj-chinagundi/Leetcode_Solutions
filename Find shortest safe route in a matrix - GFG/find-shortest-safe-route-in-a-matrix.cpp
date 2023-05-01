//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int delrow[]={0,-1,1,0};
int delcol[]={1,0,0,-1};

class Solution
{
public:
    // bool isvalid(int r,int c,vector<vector<int>>&mat){
    //     int n=mat.size();
    //     int m=mat[0].size();

    //     for(int i=0;i<4;i++){
    //         int newr=r+delrow[i];
    //         int newc=c+delcol[i];
    //         if(newr>=0 && newc>=0 && newr<n && newc<m && mat[newr][newc]==-1){
    //             return false;
    //         }
    //     }
        
    //     return true;
    // }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
          int n=mat.size();
          int m=mat[0].size();
          queue<pair<pair<int,int>,int>>q;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newr=i+delrow[k];
                        int newc=j+delcol[k];  
                        if(newr>=0 && newc>=0 && newr<n && newc<m &&  mat[newr][newc]==1){
                           mat[newr][newc]=-1;
                        }
                    }
                }
            }
          }
          vector<vector<int>> vis(n,vector<int>(m,0));
          for(int i=0;i<n;i++){
              if(mat[i][0]==1){
                //   if(isvalid(i,0,mat)){
                      q.push({{i,0},1});
                      vis[i][0]=1;
                //   }
              }
          }
          
          int mn=INT_MAX;
          while(!q.empty()){
              int r=q.front().first.first;
              int c=q.front().first.second;
              int steps=q.front().second;
              q.pop();
              if(c==m-1){
                  mn=min(mn,steps);
              }
              for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];  
                if(newr>=0 && newc>=0 && newr<n && newc<m && mat[newr][newc]==1 && !vis[newr][newc]){
                //   if(isvalid(newr,newc,mat)){
                       q.push({{newr,newc},steps+1});
                       vis[newr][newc]=1;
                //   }
                }
              }
          }
          if(mn!=INT_MAX)
          return mn;
          else
          return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends