class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findP(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findP(parent[u]);
        }
        
        void unionBySize(int u,int v){
            int upu=findP(u);
            int upv=findP(v);
            
            if(upu==upv)return;
            if(size[upu]>size[upv]){
                parent[upv]=upu;
                size[upu]+=size[upv];
            }
            else{
                parent[upu]=upv;
                size[upv]+=size[upu];                
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.count(mail)==0){
                    mp[mail]=i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        vector<string> merged_mails[n];//adj list
          
        for(auto it:mp){
            string mail_id=it.first;
            int up_node=ds.findP(it.second);
            merged_mails[up_node].push_back(mail_id);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged_mails[i].size()==0)continue;//0 mails wala push nahi ayega
            sort(merged_mails[i].begin(),merged_mails[i].end());
            vector<string> f_mail;
            f_mail.push_back(accounts[i][0]);//push name first
            for(auto m:merged_mails[i]){
                f_mail.push_back(m);
            }
            ans.push_back(f_mail);
        }
        return ans;
    }
};