class Solution {
public:
    double myPow(double x, int n) {
        long long n1=n;
        double nn=n;
        double ans=1;
        if(n1<0)n1=-1*n1;
        while(n1!=0){
            if(n1%2==0){
                x=x*x;
                n1=n1/2;
            }
            if(n1%2!=0){
                ans*=x;
                n1=n1-1;
            }
        }
        return (nn>0)?ans:((double)1/(double)ans);
    }
};