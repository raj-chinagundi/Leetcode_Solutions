//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void search(int value,int a,int b,vector<int>&ans){
        if(value>b)return;//not in range
        
        if(value>=a && value<=b){
            ans.push_back(value);
        }
        
        int last_digit=value%10;
        /*value=5
        prev adj=5*10+4=54
        next adj=5*10+6=56
        */
        
        //prev adjacent
        if(last_digit!=0){
            int step_num=value*10+(last_digit-1);//with a difference 1
            search(step_num,a,b,ans);
        }
        //next adjacent
        if(last_digit!=9){
            int step_num=value*10+(last_digit+1);//with a difference 1
            search(step_num,a,b,ans);            
        }
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        vector<int> ans;
        if(n==0){
            ans.push_back(0);
        }
        for(int i=1;i<=9;i++){
            search(i,n,m,ans);
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends