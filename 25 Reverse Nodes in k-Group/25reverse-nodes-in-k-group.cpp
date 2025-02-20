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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int c=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            c++;
            if(c==k) break;
        }
        if(c<k) return head;
        ListNode* s = temp, *r = head;
        ListNode* q = reverseKGroup(temp,k);
        temp = head;
        ListNode* prev=NULL, *nex= temp->next;
        while(temp!=s){
            temp->next = prev;
            prev = temp;
            temp = nex;
            if(nex) nex = nex->next;
        }
        r->next = q;
        return prev;

    }
};