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
    ListNode* sortList(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int arr[50001];
        temp=head;
        for(int i=0; i<count; i++){
            arr[i]=temp->val;
            temp=temp->next;
        }
        sort(arr,arr+count);
        temp=head;
        for(int i=0; i<count; i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;
    }
};