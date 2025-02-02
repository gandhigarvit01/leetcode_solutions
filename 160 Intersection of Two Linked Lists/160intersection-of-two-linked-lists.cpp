/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode* ha=headA;
        ListNode* hb=headB;

        while( ha != hb)
        {
            ha=(ha==NULL)?headB:ha->next;
            hb=(hb==NULL)?headA:hb->next;
        }
        return ha;
    }
};