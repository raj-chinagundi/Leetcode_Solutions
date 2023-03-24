class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &grid,queue<pair<int,int>> &q){
        int n=grid.size();
        int m=grid[0].size();
        if(sr<0 or sc <0 or sr>=n or sc>=m or grid[sr][sc]==0 or grid[sr][sc]==2)return;
        
        grid[sr][sc]=2;
        q.push({sr,sc});
        
        dfs(sr+1,sc,grid,q);
        dfs(sr-1,sc,grid,q);
        dfs(sr,sc+1,grid,q);
        dfs(sr,sc-1,grid,q);
    }
    int bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q){
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int d=0;
        int mindis=INT_MAX;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];

                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1){
                        mindis=min(mindis,d);
                    }
                    else if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==0){
                        q.push({nrow, ncol});
                        grid[nrow][ncol]=2;
                    }
                }
            }
            d++;
        }
        return mindis;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sr=-1;
        int sc=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                    break;
                }
            }
        }
        queue<pair<int,int>> q;
        dfs(sr,sc,grid,q);
        return bfs(grid,q);
    }
};