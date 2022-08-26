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
bool ans(TreeNode* a,TreeNode*b){
    if((a!=NULL and b==NULL)||(a==NULL and b!=NULL)) return false;
    if(a==NULL and b==NULL) return true;
    if(a->val!=b->val)return false;
    return ans(a->left,b->left)&&ans(a->right,b->right);
} 
    bool isSameTree(TreeNode* p, TreeNode* q) {
    return ans(p,q);
}
};