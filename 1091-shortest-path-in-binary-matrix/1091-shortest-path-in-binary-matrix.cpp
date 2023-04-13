class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)return -1;
        if(n-1==0 and m-1==0)return 1;
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        set<pii> st;
        st.insert({1,{0,0}});
        dist[0][0]=1;
        
        int dr[]={-1,0,1,0,-1,1,1,-1};
        int dc[]={0,-1,0,1,1,-1,1,-1};
        
        while(!st.empty()){
            auto it=*st.begin();
            int row=it.second.first;
            int col=it.second.second;
            int dis=it.first;
            st.erase(it);
            
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0){
                    if(dis+1<dist[nrow][ncol]){
                        if(nrow==n-1 and ncol==m-1){
                            return dis+1;
                        }
                        if(dist[nrow][ncol]!=1e9){
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        dist[nrow][ncol]=dis+1;
                        st.insert({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};