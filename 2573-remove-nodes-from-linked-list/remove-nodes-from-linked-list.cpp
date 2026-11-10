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
class Solution {
    private:
    ListNode* reverselist(ListNode* head) {
         ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

public:

    ListNode* removeNodes(ListNode* head) {
      
     if(head==NULL||head->next==NULL)return NULL;
     head=reverselist(head);
     ListNode* curr=head;
     int maxvel=curr->val;

     while(curr->next!=nullptr){
        if(curr->next->val<maxvel){
            ListNode* tempnode=curr->next;
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
            maxvel=curr->val;
        }
     }


return reverselist(head);

    }
};