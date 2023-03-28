class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findP(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findP(parent[u]);//path compression;
        }
        
        bool unionByRank(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            
            if(upu==upv)return false;
            if(rank[upv]>rank[upu]){
                parent[upu]=upv;
            }
            else if(rank[upu]>rank[upv]){
                parent[upv]=upu;
            }            
            else{
                parent[upv]=upu;
                rank[upu]++;
            }
            return true;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n-1);
        for(auto x:connections){
            int u=x[0];
            int v=x[1];
            
            ds.unionByRank(u,v);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findP(i)==i)count++;
        }
        int num_edges=connections.size();
        return (num_edges<n-1)?-1:count-1;
    }
};