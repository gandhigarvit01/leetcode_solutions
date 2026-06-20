/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca;
    void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p || root==q){
            lca = root;
            return;
        }
        else if(root->val > p->val && root->val < q->val){
            lca = root;
            return;
        }
        else if(root->val > p->val && root->val > q->val){
            solve(root->left,p,q);
        }
        else solve(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val) solve(root,p,q);
        else solve(root,q,p);
        return lca;
    }
};