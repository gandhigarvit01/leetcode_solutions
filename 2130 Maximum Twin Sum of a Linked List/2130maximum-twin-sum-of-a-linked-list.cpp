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
    int pairSum(ListNode* head) {
        int ans = 0;
        int n = 0;
        ListNode* tail = head;
        while(tail!=NULL){
            n++;
            tail = tail->next;
        }
        n = (n/2) - 1;
        tail = head;
        while(n--){
            tail = tail->next;
        }
        ListNode* prev = tail;
        tail = tail->next;
        prev->next = NULL;
        ListNode* curr = tail->next;
        prev = NULL;
        while(tail!=NULL){
            tail->next = prev;
            prev = tail;
            tail = curr;
            if(curr) curr = curr->next;
        }
        tail = prev;
        while(head!=NULL){
            ans = max(ans, (head->val + tail->val));
            head = head->next;
            tail = tail->next;
        }
        return ans;
    }
};