class Solution {
public:
    bool isValid(vector<vector<int>>& image, int i, int j, int n, int m , int color2){
        
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == color2)
            return true;
        
        return false;
    }
        
    void floodFillRec(vector<vector<int>>& image, int i, int j, int n, int m , int color2, int newColor){
        
        image[i][j] = newColor;
        
        if(isValid(image, i+1, j, n, m , color2))
            floodFillRec(image, i+1, j, n, m , color2, newColor);
        
        if(isValid(image, i-1, j, n, m , color2))
            floodFillRec(image, i-1, j, n, m , color2, newColor);
        
        if(isValid(image, i, j+1, n, m , color2))
            floodFillRec(image, i, j+1, n, m , color2, newColor);
        
        if(isValid(image, i, j-1, n, m , color2))
            floodFillRec(image, i, j-1, n, m , color2, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        //color2 is old color
        int color2 = image[sr][sc];
        
        if(color2 == color)
            return image;
        
        floodFillRec(image, sr, sc, n, m, color2, color);
        
        return image;
    }
};