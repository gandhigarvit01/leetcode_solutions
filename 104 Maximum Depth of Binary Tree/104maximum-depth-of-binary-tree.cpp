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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        int l_depth = depth(root->left);
        int r_depth = depth(root->right);
        return 1 + max(l_depth,r_depth);
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};