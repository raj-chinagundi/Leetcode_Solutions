class Solution {
public:
    #define ppiii pair<int,pair<int,int>>
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        if(grid[0][0]==1)return -1;
        if(n-1==0 and m-1==0)return 1;
        
        priority_queue<ppiii,vector<ppiii>,greater<ppiii>> q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        int dr[]={-1,0,1,0,-1,1,1,-1};
        int dc[]={0,-1,0,1,1,-1,1,-1};
        
        while(!q.empty()){
            auto it=q.top();
            int row=it.second.first;
            int col=it.second.second;
            int d=it.first;
            q.pop();
            
            for(int i=0;i<8;i++){
                int nrow=dr[i]+row;
                int ncol=dc[i]+col;
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0 and d+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=d+1;
                        if(nrow==n-1 and ncol==m-1){
                            return d+1;
                        }
                        q.push({d+1,{nrow,ncol}});
                }
            }
            
        }
        return -1;
    }
};