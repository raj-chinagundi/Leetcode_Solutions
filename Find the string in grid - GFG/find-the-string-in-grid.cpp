//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans;

    // move in 8 directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == word[0]) {
                // check if the word can be found in any of the 8 directions
                for (int k = 0; k < 8; k++) {
                    string curr_word = "";
                    int row = i;
                    int col = j;
                    while (row >= 0 && row < n && col >= 0 && col < m && curr_word.length() < word.length()) {
                        curr_word += grid[row][col];
                        if (curr_word[curr_word.length() - 1] != word[curr_word.length() - 1]) {
                            break;
                        }
                        //keep moving in same kth direction
                        row += dr[k];
                        col += dc[k];
                    }
                    if (curr_word == word) {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }

    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends