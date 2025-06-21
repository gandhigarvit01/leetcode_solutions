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
    int minval = INT_MAX;
    int k = INT_MAX;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        minval = min(minval,abs(root->val-k));
        k = root->val;
        solve(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return minval;
    }
};