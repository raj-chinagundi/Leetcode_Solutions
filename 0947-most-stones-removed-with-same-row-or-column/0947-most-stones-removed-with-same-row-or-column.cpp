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
        
        void unionByRank(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            
            if(upu==upv)return;
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
        }
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        int maxR=0;
        int maxC=0;
        for(auto it:stones){
            maxR=max(maxR,it[0]);
            maxC=max(maxC,it[1]);
        }
        int count=0;
        // vector<vector<int>> matrix(maxR+1,vector<int>(maxC+1,0));
        DisjointSet ds(maxR+maxC+1); 
        unordered_map<int, int> stoneNodes;
        for(auto it:stones){
            int noder=it[0];
            int nodec=it[1]+1+maxR;//0 col + max R count + 1
            ds.unionByRank(noder,nodec);
            stoneNodes[noder] = 1;
            stoneNodes[nodec] = 1;
        }
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findP(it.first) == it.first) {
                cnt++;
            }
        }
        int n=stones.size();
        return n-cnt;       
    }
};