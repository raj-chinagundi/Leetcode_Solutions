class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        vector<int> indegree(n+1,0);
        for(auto x:trust){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=1;i<=n;i++){
            if(adj[i].empty() && indegree[i]==n-1)return i;
        }
        return -1;
    }
};