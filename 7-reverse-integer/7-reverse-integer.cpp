class Solution {
public:
    int reverse(int x) {
        int alpha=pow(-2,31);
        int beta=pow(2,31)-1;
        cout<<beta;
        int temp=x;
        long long int a=0;
        while(x!=0){
            int r=x%10;
            a=a*10+r;
            if(a<=alpha||a>=beta){
                return 0;
            }
            x=x/10;
        }
        return a;
    }
};