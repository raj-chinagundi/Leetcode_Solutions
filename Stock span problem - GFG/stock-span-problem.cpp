//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        vector<int> v;
    	stack<pair<int,int>> s;
    	for(int i=0;i<n;i++){
    		while(!s.empty() and price[i]>=s.top().first){
    			s.pop();
    		}
    		if(s.empty())v.push_back(-1);
    		else v.push_back(s.top().second);
    		s.push({price[i],i});
    	}
    	for(int i=0;i<n;i++){
    	    int x=i-v[i];
    	    v[i]=x;
    	}
    	return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends