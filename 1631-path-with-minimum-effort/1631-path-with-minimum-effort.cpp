class Solution {
public:
    #define ppi pair<int,pair<int,int>> 
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 and col==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    //abhi tak hitna bhi traverse kiya uss path mai uska max effort store krunga
                    int effort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                    if(effort<dist[nrow][ncol]){
                        dist[nrow][ncol]=effort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});                        
                    }
                }
            }    
        }
        return -1;
    }
};