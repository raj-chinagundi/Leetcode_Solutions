class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)q.push(adjNode);
            }
        }
        if(topo.size()==numCourses)return true;
        else return false;
    }
};