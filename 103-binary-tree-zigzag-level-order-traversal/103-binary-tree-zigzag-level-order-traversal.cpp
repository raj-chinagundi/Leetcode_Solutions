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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        int count=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> sol;  
            while(size>0){
                TreeNode* temp=q.front();
                q.pop();
                sol.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                size--;
            }
            if(count%2==0){
                reverse(sol.begin(),sol.end());
                ans.push_back(sol);
            }
            else{
                ans.push_back(sol);
            }
            count=count+1;
        }
        return ans;
    }
};