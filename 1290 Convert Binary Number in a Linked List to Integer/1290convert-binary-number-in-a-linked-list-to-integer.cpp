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
    int getDecimalValue(ListNode* head) {
        int number = 0;
        ListNode* prev = NULL;
        ListNode* curr = head->next;
        while(head->next!=NULL){
            head->next = prev;
            prev = head;
            head = curr;
            curr = curr->next;
        }
        head->next = prev;
        int i = 0;
        while(head!=NULL){
            number += (1<<i)*head->val;
            head = head->next;
            i++;
        }
        return number;
    }
};