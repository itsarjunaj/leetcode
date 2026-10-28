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
class BSTIterator {
    stack<TreeNode*>stack;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
       TreeNode *tempnode=stack.top();
       stack.pop();
       pushall(tempnode->right);
       return tempnode->val;
        
    }
    
    bool hasNext() {
       return !stack.empty();
    }
    private: 
    void pushall(TreeNode* root){
        while(root!=NULL){
            stack.push(root);
            root=root->left;}
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */