class Solution {
public:
    void f(int n,string &temp,vector<string> &ans,int i=0,int j=0){
        //i is open brack count
        //j is close brack count
        if(i==n && j==n){
            ans.push_back(temp);
            return;
        }
        if(i+1<=n){
            temp.push_back('(');
            f(n,temp,ans,i+1,j);
            temp.pop_back();
        }
        if(j+1<=n and j+1<=i){
            temp.push_back(')');
            f(n,temp,ans,i,j+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string temp;
            f(n,temp,ans);
            return ans;
    }
};