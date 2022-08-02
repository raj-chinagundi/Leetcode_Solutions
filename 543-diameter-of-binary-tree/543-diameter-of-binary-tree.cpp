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
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int travel(TreeNode* root){
        if(root==NULL) return 0;
            
            int leftHeight = height(root->left);
            int rightHeight  = height(root->right);
           int lc= travel(root->left);
           int rc= travel(root->right);
           return max(1+leftHeight+rightHeight,max(lc,rc));
        }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans;
        ans=travel(root);
        return ans-1;
    }
};