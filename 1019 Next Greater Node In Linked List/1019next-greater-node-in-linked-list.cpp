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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        int c=0;
        if(head->next==NULL) return {0};
        ListNode* curr=head, *prev=NULL, *nex=head->next;
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = nex;
            if(nex) nex = nex->next;
            c++;
        }
        vector<int> v(c,0);
        for(int i=c-1; i>=0; i--){
            if(st.empty()){
                v[i]=0;
                st.push(prev->val);
            }
            else if(prev->val<st.top()){
                v[i]=st.top();
                st.push(prev->val);
            }
            else{
                while(!st.empty() && st.top()<=prev->val){
                    st.pop();
                }
                if(st.empty()){
                    v[i] = 0;
                    st.push(prev->val);
                }
                else{
                    v[i] = st.top();
                    st.push(prev->val);
                } 
            }
            prev = prev->next;
        }
        return v;
    }
};