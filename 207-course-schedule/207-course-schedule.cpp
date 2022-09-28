class Solution {
public:
    bool dfsrec(int node,vector<int> &vis,vector<int> &currVis,vector<int> adj[]){
        vis[node]=1;
        currVis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfsrec(i,vis,currVis,adj)){
                    return true;
                }
            }
            else if(currVis[i]==1 &&vis[i]==1){
                    return true;
            } 
        }
        currVis[node]=0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> vis(n+1,0),currVis(n+1,0);
        vector<int> adj[n+1];
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfsrec(i,vis,currVis,adj)){
                 return false;   
                }
            }
        }
        return true;
    }
};