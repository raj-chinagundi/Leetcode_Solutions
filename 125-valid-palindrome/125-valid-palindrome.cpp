class Solution {
public:
    bool valid(char ch){
        if((ch>='a' and ch<='z')||(ch>='A' and ch<='Z')||(ch>='0' and ch<='9')){
            return 1;
        }
        else{
            return 0;
        }
    }
    char toLOWER(char m){
        if((m>='a' and m<='z')||(m>='0' and m<='9')){
            return m;
        }
        else{
            return m-'A'+'a';
        }
    }
    bool isPalindrome(string s) {
    string n;
    for(int i=0;i<s.length();i++){
        if(valid(s[i])){
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