class Solution {
public:
    
    vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;    
    void f(string &digits,string &temp,vector<string>&ans,int ind){
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto x:keypad[digits[ind]-'0']){
            temp.push_back(x);
            f(digits,temp,ans,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }

        string temp;
        f(digits,temp,ans,0);
        return ans;
    }
};