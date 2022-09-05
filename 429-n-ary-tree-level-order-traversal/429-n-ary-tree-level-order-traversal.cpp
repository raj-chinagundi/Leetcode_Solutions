/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> lvl;
            while(size>0){
            Node* temp=q.front();
            q.pop();
            lvl.push_back(temp->val);
            for(auto it:temp->children){
                    q.push(it);
            }
            size--;
           }
           ans.push_back(lvl);
        }
        return ans;
    }
};