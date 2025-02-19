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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        dummy->next=head;
        ListNode *t=dummy,*s= dummy,*p = dummy;
        while(left>1){
            t = t->next;
            left--;
        }
        s=t->next;
        while(right>-1){
            p = p->next;
            right--;
        }
        ListNode* prev = t;
        ListNode* curr = prev->next;
        ListNode* nex = curr->next;
        while(curr!=p){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex) nex=nex->next;
        }
        s->next = curr;
        t->next = prev;
        if(t==dummy) return prev;
        else return head;
    }
};