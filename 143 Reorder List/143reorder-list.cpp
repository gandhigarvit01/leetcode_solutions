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
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        int total = 0;
        ListNode* l1 = head;
        ListNode* l2;
        while(l1!=NULL){
            total++;
            l1 = l1->next;
        }
        int half = total%2==0? total/2 - 1: total/2;
        l1 = head;
        while(half--){
            l1 = l1->next;
        }
        l2 = l1->next;
        l1->next = NULL;
        ListNode* c1 = NULL;
        ListNode* c2 = l2->next;
        while(l2!=NULL){
            l2->next = c1;
            c1 = l2;
            l2 = c2;
            if(c2) c2 = c2->next;
        }
        l2 = c1;
        l1 = head;
        c1 = l1->next;
        c2 = l2->next;
        while(l1!=NULL && l2!=NULL){
            l1->next = l2;
            l2->next = c1;
            l1 = c1;
            if(c1) c1 = c1->next;
            l2 = c2;
            if(c2) c2 = c2->next;
        }
    }
};