class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++)dist[i][i]=0;
                
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int wt=x[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        
        //create shortest distance matrix by floyd warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e9||dist[k][j]==1e9)continue;
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        
        int city=-1;
        int mxC=n;
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                 count++;   
                }
            }
            if(count<=mxC){
                mxC=count;
                city=i;
            }
        }
        
        return city;
    }
};