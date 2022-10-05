class Solution {
public:
    bool reverse(string a){
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
    bool isPalindrome(int x) {
        return reverse(to_string(x));
    }
};