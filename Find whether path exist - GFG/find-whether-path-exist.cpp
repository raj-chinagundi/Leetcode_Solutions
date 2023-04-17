//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        int sr=-1,sc=-1;
        int er=-1,ec=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    er=i;
                    ec=j;
                }                
            }

        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow==er and ncol==ec){
                    return 1;
                }
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==3){
                    q.push({nrow,ncol});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends