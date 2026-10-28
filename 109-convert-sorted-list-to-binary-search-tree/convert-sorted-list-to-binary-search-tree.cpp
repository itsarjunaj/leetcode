/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
int size(ListNode* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
       
    }
   return count;
}
TreeNode* LLtoBST(ListNode* &head,int n){
    if(head==NULL||n<=0)return NULL;
    TreeNode* leftsubtree=LLtoBST(head,n/2);
    TreeNode* root=new TreeNode(head->val);
    root->left=leftsubtree;
    head=head->next;
    root->right=LLtoBST(head,n-(n/2)-1);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        int n=size(head);
        TreeNode* root=LLtoBST(head,n);
       
return root;
    }
};