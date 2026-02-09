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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* Head;
    bool solve(ListNode* head, TreeNode* root){
        if(head==NULL) return true;
        if(root==NULL) return false;
        bool case1 = false, case2 = false;
        if(root->val == head->val){
            case1 = solve(head->next,root->left);
            case2 = solve(head->next,root->right);
        }
        return (case1 || case2);
    }
    bool traverse(ListNode* head, TreeNode* root){
        if(root==NULL) return false;
        bool a = false;
        if(root->val==head->val){
            a = solve(head,root);
        }
        bool l = traverse(head,root->left);
        bool r = traverse(head,root->right);
        return (a || l || r);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        Head = head;
        return traverse(head,root);
    }
};