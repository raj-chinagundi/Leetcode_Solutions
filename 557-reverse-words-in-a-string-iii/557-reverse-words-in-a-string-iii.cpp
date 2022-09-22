class Solution {
public:
    string rev(string& str)
    {
        int len = str.length();
        int n = len-1;
        int i = 0;
        while(i<=n){
            //Using the swap method to switch values at each index
            swap(str[i],str[n]);
            n = n-1;
            i = i+1;
        }
        return str;
  }
    
    string reverseWords(string s) {
        string ans="";
        string n="";
        char sp=' ';
        for(auto i:s){
            // cout<<i;  
            n.push_back(i); 
            if(i==sp){
                // cout<<"space";
                string reversed=rev(n);
                // cout<<reversed<<endl;
                ans.append(reversed);
                n.clear();
            }        
        }
        n.push_back(sp); 
        string last_reversed=rev(n);
        ans.append(last_reversed);
        string f="";
        for(int i=1;i<ans.length();i++){
            f.push_back(ans[i]);
        }
        return f;
    }
};