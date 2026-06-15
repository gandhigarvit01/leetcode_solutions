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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }

        prev->next=slow->next;
        slow->next=nullptr;
        return head;

    }
};