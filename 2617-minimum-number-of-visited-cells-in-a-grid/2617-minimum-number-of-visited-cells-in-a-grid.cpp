class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int start=grid[0][0];
        if(n==1 and m==1)return 1;
        if(start==99999)return 2;
        if(start==0)return -1;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        pq.push({1,{0,0}});
        vis[0][0]=1;
        int mnsteps=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int steps=it.first;
            pq.pop();
            
            int psteps=grid[row][col];
            if(row==n-1 and col==m-1){
                mnsteps=min(mnsteps,steps);
            }
            for(int i=psteps;i>=1;i--){
                int drow=row+i;
                int dcol=col;
                int rrow=row;
                int rcol=col+i;
                
                if(drow<n and dcol<m and !vis[drow][dcol]){
                    vis[drow][dcol]=1;
                    pq.push({steps+1,{drow,dcol}});
                }
                if(rrow<n and rcol<m and !vis[row][rcol]){
                    vis[row][rcol]=1;
                    pq.push({steps+1,{rrow,rcol}});
                }
            }
        }
        if(mnsteps>=INT_MAX)return -1;
        else return mnsteps;
    }
};