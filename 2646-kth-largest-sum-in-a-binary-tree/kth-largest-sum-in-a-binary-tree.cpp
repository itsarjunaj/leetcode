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
    long long kthLargestLevelSum(TreeNode* root, int k) {
          if (root == NULL) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long>sums;

        while (!q.empty()) { 
            long long sum=0;
            int Size = q.size(); 
            for (int i = 0; i < Size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            sums.push_back(sum);
        }
        int arrsize=sums.size();
        if(k>arrsize) return -1;
       sort(sums.begin(),sums.end());
       return sums[arrsize-k];
        
    }
};