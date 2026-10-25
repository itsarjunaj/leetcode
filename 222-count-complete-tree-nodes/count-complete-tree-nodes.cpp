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
//O(n) approach
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root==NULL)return 0;
//         int ans=0;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* temp=q.front();
//             q.pop();
//             ans+=1;
          
//            if(temp->left){
//             q.push(temp->left);
//            }
//             if(temp->right){
//             q.push(temp->right);
//            }

//         }
//    return ans; }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode* left = root;
        TreeNode* right = root;

        while (left != NULL) {
            leftHeight++;
            left = left->left;
        }

        while (right != NULL) {
            rightHeight++;
            right = right->right;
        }

       
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        
        return 1 + countNodes(root->left) + countNodes(root->right);}
};