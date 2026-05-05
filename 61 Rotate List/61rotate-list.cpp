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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp= head;
        ListNode* t=head;
        int m=0;
        while(temp!=NULL && temp->next!=NULL){
            m++;
            temp=temp->next;
        }
        m++;
        
        int n=k%m;
        int c=m-n;
        while(c>1){
            t=t->next;
            c--;

        }
        temp->next=head;
        ListNode* start=t->next;
        t->next=NULL;
        return start;

    }
};