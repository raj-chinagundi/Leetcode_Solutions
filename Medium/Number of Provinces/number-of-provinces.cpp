//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        int n=adj.size();
        int m=adj[0].size();
        int id = 1;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i+1,j+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=V;i++){
            if(ds.findP(i)==i){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends