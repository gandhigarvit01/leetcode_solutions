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
        ListNode* t= head;
        ListNode* temp = head;
        ListNode* s= NULL;
        int c=0;
        if(head==NULL || head->next==NULL){
            return head;
        }
        int k=101;
        ListNode* p= t->next;
        while(p!=NULL){
            if(t->val==p->val){
                if(p->next==NULL){
                    k=p->val;
                }
                c=1;
                t->next=p->next;
                p->next=NULL;
                p=t->next;
            }
            else if(t->val!=p->val && c==1){
                c=0;
                if(temp==t){
                    t=p;
                    temp=p;
                    p=p->next;
                }
                else{
                    s->next=p;
                    t->next=NULL;
                    t=p;
                    p=p->next;
                }
            }
            else{
                s=t;
                t=p;
                p=p->next;
            }
        }
        if(t==temp && t->val==k) return NULL;
        else if(t->val==k){
            s->next=NULL;
        }
        return temp;
    }
};