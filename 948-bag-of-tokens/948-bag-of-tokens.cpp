class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int c=0;
        for(auto i:tokens){
            if(power<i){
                c++;
            }
        }
        if(tokens.size()==0 ||c==tokens.size()){
            return 0;
        }
        int n=tokens.size();
        int s=0;
        int e=n-1;
        sort(tokens.begin(),tokens.end());
        int score=0;
        int mx=INT_MIN;
        while(s<=e&&power>=0){
            if(tokens[s]<=power){
                power=power-tokens[s];
                score++;
                s++;
            }
            else if(tokens[s]>power){
                power=power+tokens[e];
                score--;
                e--;
            }
            cout<<power<<endl;
            mx=max(mx,score);
        }
        return mx;
    }
};