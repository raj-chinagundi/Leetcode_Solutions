class Solution {
public:
    void dfs(int i,int j,int scolor,int color,vector<vector<int>> &vis,vector<vector<int>> &img){
        int n=img.size();
        int m=img[0].size();
        if(i<0 || j<0 || i>=n || j>=m || img[i][j]!=scolor || vis[i][j]==1) return;
        
        img[i][j]=color;
        vis[i][j]=1;
        
        dfs(i+1,j,scolor,color,vis,img);
        dfs(i,j+1,scolor,color,vis,img);
        dfs(i-1,j,scolor,color,vis,img);
        dfs(i,j-1,scolor,color,vis,img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int scolor=image[sr][sc];
        vector<vector<int>> vis(n,vector<int> (m,0));
        dfs(sr,sc,scolor,color,vis,image);
        return image;
    }
};