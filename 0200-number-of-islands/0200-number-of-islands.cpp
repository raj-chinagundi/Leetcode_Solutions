class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& grid){
            visited[i][j] = 1;
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<int, int>> q;
            q.push({i,j});
              // delta row and delta column
            int a[4] = {-1, 0, +1, 0}; 
            int b[4] = {0, -1, 0, +1}; 
            while (!q.empty())
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

               	//checking all  8 direction (according to the video)
                for (int delcol = 0; delcol <4; delcol++)
                {

                        int nrow = a[delcol] + row;
                        int ncol = b[delcol] + col;
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0)
                        {
                            visited[nrow][ncol] = 1;
                            q.push({ nrow,
                                ncol });
                        }
                }
            }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};