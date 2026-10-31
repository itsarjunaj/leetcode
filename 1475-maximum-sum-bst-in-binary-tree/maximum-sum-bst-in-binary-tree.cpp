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

    class NodeData {
    public:
        int sum;
        int minVal;
        int maxVal;
        bool validBST;

        NodeData(int s, int mx, int mn, bool valid) {
            sum = s;
            maxVal = mx;
            minVal = mn;
            validBST = valid;
        }
    };
    NodeData solve(TreeNode* root, int &ans) {

        // Base case
        if(root == NULL) {
            return NodeData(0, INT_MIN, INT_MAX, true);
        }

        // Recursive calls
        NodeData left = solve(root->left, ans);
        NodeData right = solve(root->right, ans);

        // Current node information
        NodeData curr(0, 0, 0, false);

        curr.sum = left.sum + right.sum + root->val;

        curr.maxVal = max(root->val, right.maxVal);
        curr.minVal = min(root->val, left.minVal);

        // Check BST condition
        if(left.validBST && right.validBST &&
           root->val > left.maxVal &&
           root->val < right.minVal) {

            curr.validBST = true;

            ans=max(ans,curr.sum);
        }
        else {
            curr.validBST = false;
          
        }

        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
        
    }
};