class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &grid,queue<pair<pair<int,int>,int>> &q){
        int n=grid.size();
        int m=grid[0].size();
        if(sr<0 or sc <0 or sr>=n or sc>=m or grid[sr][sc]==0 or grid[sr][sc]==2)return;
        
        grid[sr][sc]=2;
        q.push({{sr,sc},0});
        
        dfs(sr+1,sc,grid,q);
        dfs(sr-1,sc,grid,q);
        dfs(sr,sc+1,grid,q);
        dfs(sr,sc-1,grid,q);
    }
    int bfs(vector<vector<int>> &grid,queue<pair<pair<int,int>,int>> &q){
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        int mn=INT_MAX;
        
        while(!q.empty()){
                int row=q.front().first.first;
                int col=q.front().first.second;
                int d =q.front().second;
                
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];

                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1){
                        mn=min(mn,d);//update distance if you find 1 through any bfs from sources
                    }
                    else if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==0){
                        q.push({{nrow, ncol},d+1});//keep increasing 1 lvl
                        grid[nrow][ncol]=2;
                    }
                }

        }
        return mn;
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
        queue<pair<pair<int,int>,int>> q;
        dfs(sr,sc,grid,q);
        return bfs(grid,q);
    }
};