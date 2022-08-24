class Solution {
public:
    void reverseString(vector<char>& s) {
        int size=s.size()-1;
        for(int i=0;i<=size/2;i++){
            char temp;
            temp=s[size-i];
            s[size-i]=s[i];
            s[i]=temp;
        }
        // reverse(s.begin(),s.end());
    }
};