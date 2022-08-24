class Solution {
public:
    bool isPalindrome(string s) {
    string n;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i]) or isdigit(s[i])){
            n.push_back(tolower(s[i]));
        }
    }
    int st=0;
    int end=n.length()-1;
    while(st<=end){
        if(n[st]!=n[end])return false;
        else{
            st++;
            end--;
        }
    }
        return true;
    }
};