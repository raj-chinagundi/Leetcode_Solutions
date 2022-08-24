class Solution {
public:
    char toLOWER(char m){
        if(m>='a' and m<='z'){
            return m;
        }
        else{
            return m-'A'+'a';
        }
    }
    bool isPalindrome(string s) {
    string n;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i]) or isdigit(s[i])){
            n.push_back(toLOWER(s[i]));
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