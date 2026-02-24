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
    int solve(TreeNode* root, int old){
        if(root == NULL) return 0;
        int newval = old * 2 + root->val;
        if(root->left == NULL && root->right == NULL){
            return newval;;
        }
        return solve(root->left, newval) + solve(root->right, newval);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};