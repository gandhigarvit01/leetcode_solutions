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
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode* next=head;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        int n= count/2;
        ListNode* prev=NULL;
        temp=head;
        ListNode* curr=head->next;
        while(n>0)
        {
            temp->next=prev;
            prev=temp;
            temp=curr;
            curr=curr->next;
            n--;
        }

        if(count%2!=0){
            temp=temp->next;
        }
        while(temp!=NULL){
            if(temp->val!=prev->val){
                return false;
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }

        }
        return true;



        

    }

};