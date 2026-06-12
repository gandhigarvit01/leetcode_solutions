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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            total++;
            curr = curr->next;
        }
        int k = total-n;    // (k+1) from start;
        ListNode* prev = NULL;
        curr = head;
        while(k--){
            prev = curr;
            curr = curr->next;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};