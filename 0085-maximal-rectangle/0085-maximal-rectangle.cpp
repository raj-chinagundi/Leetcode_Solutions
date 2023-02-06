class Solution {
public:
    int mah(vector<int> &heights){
        vector<int> nsl;
        vector<int> nsr;
        int n=heights.size();
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i]<=s.top().first){
                s.pop();
            }
            if(s.empty())nsl.push_back(-1);
            else nsl.push_back(s.top().second);
            s.push({heights[i],i});
        }
        stack<pair<int,int>> s2;
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && heights[i]<=s2.top().first){
                s2.pop();
            }
            if(s2.empty())nsr.push_back(n);
            else nsr.push_back(s2.top().second);
            s2.push({heights[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        vector<int> width;
        for(int i=0;i<n;i++){
            width.push_back(nsr[i]-nsl[i]-1);
        }
        for(int i=0;i<n;i++){
            int m=heights[i]*width[i];
            width[i]=m;
        }
        return *max_element(width.begin(),width.end());
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        int mx=0;
        vector<int> v(n,0);
        for(int i=0;i<matrix.size();i++){         
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                v[j]+=1;
                else v[j]=0;
            }
            int harea=mah(v);
            mx=max(mx,harea);
        }
        return mx;
    }
};