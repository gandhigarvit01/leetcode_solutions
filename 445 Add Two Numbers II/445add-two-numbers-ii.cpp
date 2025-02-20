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
        ListNode*curr = l1, *prev = NULL, *nex = curr->next;
        ListNode* t=NULL,*p=NULL;
        int c=0,k=0,j=0,sum=0;
        while(curr!=NULL){
            k++;
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex) nex=nex->next;
        }
        ListNode* h1 = prev;
        curr = l2, prev = NULL, nex = curr->next;
        while(curr!=NULL){
            j++;
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex) nex=nex->next;
        }
        ListNode* h2 = prev;
        if(k>=j){
            t=h1;
            p=h2;
        }
        else{
            t=h2;
            p=h1;
        }
        ListNode *l = t;
        while(t!=NULL || p!=NULL){
            if(t==NULL) j=0;
            else j= t->val;
            if(p==NULL) k=0;
            else k= p->val;
            sum = j+k+c;
            t->val = sum%10;
            c = sum/10;
            t=t->next;
            if(p) p=p->next;
        }
        ListNode* s = l;
        while(s->next!=NULL){
            s=s->next;
        }
        if(c==1){
            s->next = new ListNode(1);
        }
        curr=l,prev=NULL,nex=curr->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex) nex=nex->next;
        }
        return prev;
    }
};