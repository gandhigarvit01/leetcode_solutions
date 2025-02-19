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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t= head;
        ListNode* p= head, *s = head;
        int c=0,j=k,l=0;
        while(t!=NULL){
            t=t->next;
            c++;
        }
        t = head;
        l = c-k;
        while(j>1){
            t = t->next;
            j--;
        }
        while(l>0){
            p = p->next;
            l--;
        }
        l = p->val;
        p->val = t->val;
        t->val = l;
        return head;
    }
};