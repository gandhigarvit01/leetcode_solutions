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
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int m = 0, n = 0;
    
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* p = l1;
    ListNode* q = l2;
    while (p != nullptr) {
        p = p->next;
        m++;
    }
    while (q != nullptr) {
        q = q->next;
        n++;
    }
    if (m >= n) {
        p = l1;
        q = l2;
    } else {
        p = l2;
        q = l1;
    }

    ListNode* temp = p;
    int sum = 0;
    int value=0;
    while (p != nullptr && p->next!=nullptr) {
        if(q==NULL){
            value=0;
        }
        else{
            value=q->val;
        }
        sum = p->val + value + carry;
        p->val = sum % 10;
        carry = sum / 10;
        p = p->next;
        if(q!=NULL){
        q = q->next;}
    }
    if(q==NULL){
        value=0;
    }
    else{
        value=q->val;
    }
    sum=p->val+value+carry;
    p->val=sum%10;
    carry=sum/10;

    if(carry>0){
        ListNode* k= new ListNode(1);
        p->next=k;
    }

 
    return temp;
}

};