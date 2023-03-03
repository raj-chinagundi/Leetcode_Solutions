class Solution {
public:
    int strStr(string haystack, string needle) {
        int e1=haystack.size();
        int e2=needle.size();
        for(int i=0;i<e1-e2+1;i++){
            string temp=haystack.substr(i,e2);
            cout<<temp<<endl;
            if(temp==needle)return i;
        }
        return -1;
    }
};