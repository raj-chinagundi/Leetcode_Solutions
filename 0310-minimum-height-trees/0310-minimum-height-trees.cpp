class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0){
           return {};
        }
           
        if(n==1){
            return {0};
        }     

        vector<int>adj[n];
        vector<int>indeg(n,0);
        for (auto  edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                indeg[u]++;
                indeg[v]++;
            }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            ans.clear();
            while(size>0){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==1)q.push(it);
                }
                size--;
            }
        }
       
       return ans;
     
    }
};