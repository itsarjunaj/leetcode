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
    int findBottomLeftValue(TreeNode* root) {
         if (root == NULL) return 0;

        queue<TreeNode*> queue;
        queue.push(root);

        int ans=root->val;

        while (!queue.empty()) { 
            ans=queue.front()->val;
            int queueSize = queue.size(); 
            for (int i = 0; i < queueSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);

                if (node->right)
                    queue.push(node->right);
            }
        }
        return ans;
        
    }
};