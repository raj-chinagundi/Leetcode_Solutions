/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
       vector<vector<int>> res;
                vector<double> fin;
        queue<TreeNode*> q;
        if(root==NULL){
            return fin;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ans;
            while(size>0){
                TreeNode* temp=q.front();
                q.pop();           
                ans.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                size--;
            }
            res.push_back(ans);
        }

        for(auto v:res){
            double sum=0;
            double avg=0;
            for(auto e:v){
                sum+=e;
            }
            avg=sum/v.size();
            fin.push_back(avg);
        }
        return fin;
    }
};