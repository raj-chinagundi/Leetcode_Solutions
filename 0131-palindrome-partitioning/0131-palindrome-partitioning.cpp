class Solution {
public:
    bool isPalindrome(string st,int s,int e){
        while(s<=e){
            if(st[s++]!=st[e--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0,s,v,ans);
        return ans;
    }
    void solve(int ind,string s,vector<string> &v,vector<vector<string>> &ans){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
};