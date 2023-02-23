class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> adj[numCourses];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto adjNode:adj[i]){
                indegree[adjNode]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)q.push(adjNode);
            }
        }
        if(topo.size()==numCourses)return topo;
        else return {};
    }
};