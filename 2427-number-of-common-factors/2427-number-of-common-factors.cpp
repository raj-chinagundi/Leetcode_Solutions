class Solution {
public:
    int commonFactors(int a, int b) {
        int d=0; /*storing difference between a & b*/
        int n=1; /*initializing numbers which are divisible by a & b*/
        int count=0; /*for keeping track of common factors*/

        /* Logic: Difference is set to be smallest amongst min(a,b) and abs(a-b);
            Example 1: 25,30
            difference d=5 and d<a
            Example 2: 10,4
            in this case a>b
            difference d=6 and d>b so difference is set to 4.
        */

        if(a>b){
            d=a-b;
            if(d>b){
                d=b;
            }
        }
        else if(b>a){
            d=b-a;
            if(d>a){
                d=a;
            } 
        }
		else{
            d=a;
        }
        while(n<=d){
            if(a%n==0 && b%n==0){
                count++;
            }
            n++;
        }
        return count;
    }
};