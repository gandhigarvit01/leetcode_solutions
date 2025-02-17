/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* heads = new Node(0);
        Node* temp = head;
        Node* temps= heads;
        while(temp!=NULL){
            temps->val = temp->val;
            temps->next = new Node(0);
            temps=temps->next;
            temp=temp->next;
        }
        temp=head;
        temps=heads;
        Node* t =temps;
        int j=0,k=0;
        Node* p=head;
        while(temp!=NULL){
            t = heads;
            p = head;
            j=0,k=0;
            if(temp->random!=NULL){
               while(p!=temp->random){
                j++;
                p=p->next;
               }
               k=j;
               while(k>0){
                k--;
                t=t->next;
               }
               temps->random=t;
               temp=temp->next;
               temps=temps->next;
            }
            else{
                temps->random=NULL;
                temp=temp->next;
                temps=temps->next;
            }
        }
        temps=heads;
        while(temps->next->next!=NULL){
            temps=temps->next;
        }
        temps->next=NULL;
        return heads;
    }
};