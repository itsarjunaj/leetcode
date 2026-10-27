/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //last approach
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL)return NULL;
//         if(root->val==p->val){
//             return p;
//         }
//         if(root->val==q->val){
//             return q;
//         }
//        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
//        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
//        //as we know p and q must exist in tree below line will have no significant
//        //if(leftans==NULL&&rightans==NULL)return NULL;
//        if(leftans!=NULL&&rightans!=NULL)return root;
//        return leftans!=NULL?leftans:rightans;
       
//     }
// };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(p->val<root->val&&q->val<root->val){
          return lowestCommonAncestor(root->left,p,q);
            
        }
       else if(p->val>root->val&&q->val>root->val){
       return lowestCommonAncestor(root->right,p,q);
       
       }
       else{
        return root;
       }
      
       
    
    
       
    }
};