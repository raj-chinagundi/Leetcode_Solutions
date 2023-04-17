//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        // Code here
        vector<vector<int>> dist(N,vector<int>(N,1e9));
        
        int er=TargetPos[0]-1;
        int ec=TargetPos[1]-1;
        
        int dr[]={2,1,-1,2,-1,-2,-2,1};
        int dc[]={1,2,2,-1,-2,-1,1,-2};
        
        set<pair<int,vector<int>>> st;
        st.insert({0,{KnightPos[0]-1,KnightPos[1]-1}}); // fix
        
        while(!st.empty()){
           auto it=*st.begin();
           int row=it.second[0];
           int col=it.second[1];
           int steps=it.first;
           st.erase(it);
           
           for(int i=0;i<8;i++){
               int nrow=row+dr[i];
               int ncol=col+dc[i];
               
               if(nrow==er and ncol==ec){
                   return steps+1;
               }
               
               if(nrow>=0 and nrow<N and ncol>=0 and ncol<N){
                   if(steps+1<dist[nrow][ncol]){
                       if(dist[nrow][ncol]!=1e9){
                           st.erase({dist[nrow][ncol],{nrow,ncol}});
                       }
                       dist[nrow][ncol]=steps+1;
                       st.insert({dist[nrow][ncol],{nrow,ncol}});
                   }
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends