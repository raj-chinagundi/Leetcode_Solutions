//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord});
        vector<string> usedWords;
        usedWords.push_back(beginWord);
        int lvl=0;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if (vec.size() > lvl)
            {
                lvl++;
                for (auto it : usedWords)
                {
                    st.erase(it);
                }
            }
            
            string word=vec.back();
            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                ans.push_back(vec);
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        
                        vec.pop_back();
                        usedWords.push_back(word);
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends