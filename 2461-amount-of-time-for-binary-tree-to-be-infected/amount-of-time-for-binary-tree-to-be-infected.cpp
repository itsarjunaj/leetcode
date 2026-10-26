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
    int ans = 0;

    int solve(TreeNode* root, int start) {
        if (root == NULL)
            return 0;

        int left = solve(root->left, start);
        int right = solve(root->right, start);

        if (root->val == start) {
            ans = max(left, right);
            return -1;
        }

        if (left >= 0 && right >= 0) {
            return 1 + max(left, right);
        }

        ans = max(ans, abs(left) + abs(right));

        return min(left, right) - 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        solve(root, start);
        return ans;
    }
};