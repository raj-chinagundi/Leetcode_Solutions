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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int act_h=max(lh,rh)+1;
        return act_h;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftsub=height(root->left);
        int rightsub=height(root->right);
        
        if(abs(leftsub-rightsub)<2){
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        else{
            return false;
        }

    }
};