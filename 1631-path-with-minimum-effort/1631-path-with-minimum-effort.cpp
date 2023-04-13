class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        set<pii> st;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        //diff of effort in path,bfs point
        st.insert({0,{0,0}});
        dist[0][0]=0;
        while(!st.empty()){
            auto it=*st.begin();
            int row=it.second.first;
            int col=it.second.second;
            int dis=it.first;
            st.erase(it);
            
            for(int i=0;i<4;i++){
                int nrow=dr[i]+row;
                int ncol=dc[i]+col;
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m){
                    int effort=abs(heights[nrow][ncol]-heights[row][col]);
                    int newDist = max(dist[row][col], effort); // calculate new distance
                    if(newDist < dist[nrow][ncol]){
                        if(dist[nrow][ncol]!=1e9){
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        dist[nrow][ncol]=newDist; // update distance
                        st.insert({newDist,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
        
    }
};