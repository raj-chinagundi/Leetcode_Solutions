class Solution {
public:
    bool pcheck(string a){
        int s=0;
        int e=a.length()-1;
        while(s<e){
            if(a[s]!=a[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string alpha="";
        for(auto c:s){
            if(isalpha(c)||isdigit(c)){
                alpha+=tolower(c);
            }
        }
        return pcheck(alpha);
    }
};