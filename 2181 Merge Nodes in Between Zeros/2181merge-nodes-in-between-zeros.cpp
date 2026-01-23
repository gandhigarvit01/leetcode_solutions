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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        temp = temp->next;
        ListNode* p = temp->next;
        while(temp!=NULL){
            while(p->val!=0){
            temp->val += p->val;
            temp->next = p->next;
            p = p->next;
            }
            temp->next = p->next;
            p = p->next;
            if(temp->next!=NULL){
                temp = temp->next;
                p = p->next;
            }
            else{
                break;
            }
        }
        head = head->next;
        return head;
    }
};