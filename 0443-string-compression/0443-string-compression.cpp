class Solution {
public:
    int compress(vector<char>& chars) {
        int s=0;
        cout<<chars[s]<<endl;
        int e=chars.size();
        vector<char> ans;
        while(s<e){
            int count=1;
            int p=s+1;
            while(p<e and chars[s]==chars[p]){
                     count++;
                     p++;
            }
            ans.push_back(chars[s]);
            if(count>1){
                for(auto x:to_string(count)){
                    ans.push_back(x);
                }                
            }
            s=p;
        }
        if(e>1)chars=ans;
        return chars.size();
    }
};