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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL){
            if(head->val==val) head=head->next;
            else break;
        }
        if(head==NULL) return head;
        if(head->next==NULL){
            if(head->val==val) return NULL;
            else return head;
        }
        ListNode* t=head;
        ListNode* p=t->next;
        while(p!=NULL){
            if(p->val==val){
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