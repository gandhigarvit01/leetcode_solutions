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
    int n;
    ListNode* mergetwo(ListNode* l, ListNode* r){
        if(l==NULL) return r;
        if(r==NULL) return l;
        if(l->val <= r->val){
            l->next = mergetwo(l->next,r);
            return l;
        }
        r->next = mergetwo(l,r->next);
        return r;
    }
    ListNode* solve(int l, int r, vector<ListNode*>& lists){
        if(l==r){
            return lists[l];
        }
        int mid = l + (r-l)/2;
        ListNode* left = solve(l,mid,lists);
        ListNode* right = solve(mid+1,r,lists);
        return mergetwo(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        n = lists.size();
        if(n==0) return NULL;
        ListNode* ans = solve(0,n-1,lists);
        return ans;
    }
};