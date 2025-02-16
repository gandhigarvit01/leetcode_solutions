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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* t=head;
        ListNode* p=t->next;
        while(p!=NULL){
            if(t->val==p->val){
                t->next=p->next;
                p->next=NULL;
                p=t->next;
            }
            else{
                t=p;
                p=p->next;
            }
        }
        return head;
    }
};