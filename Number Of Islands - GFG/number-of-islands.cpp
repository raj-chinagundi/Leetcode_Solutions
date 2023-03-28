//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findP(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findP(parent[u]);//path compression
        }
        
        void unionByRank(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            
            if(upu==upv)return;
            if(rank[upu]>rank[upv]){
                parent[upv]=upu;
            }
            else if(rank[upv]>rank[upu]){
                parent[upu]=upv;
            }
            else{
                parent[upu]=upv;
                rank[upv]++;
            }
        }
        void unionBySize(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            
            if(upu==upv)return;
            if(size[upu]>size[upv]){
                parent[upv]=upu;
                size[upu]+=size[upv];
            }
            else{
                parent[upu]=upv;
                size[upv]+=size[upu];                
            }
        }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        
        int cnt =0;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and vis[nrow][ncol]==1){
                    int node=row*m+col;
                    int adj_node=nrow*m+ncol;
                    if(ds.findP(node)!=ds.findP(adj_node)){
                        cnt--;
                        ds.unionBySize(node,adj_node);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends