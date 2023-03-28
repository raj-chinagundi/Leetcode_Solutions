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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int num=edges.size();
        DisjointSet ds(num);
        vector<vector<int>> ans;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            if(ds.unionByRank(u,v)==false) ans.push_back({u,v});
            
        }
        return ans.back();
    }
};