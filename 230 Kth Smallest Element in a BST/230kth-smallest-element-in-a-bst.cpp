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
    int ans;
    int val;
    void traverse(TreeNode* root){
        if(root==NULL) return;
        traverse(root->left);
        val--;
        if(val==0){
            ans = root->val;
            return;
        }
        if(val<0) return;
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        val = k;
        traverse(root);
        return ans;
    }
};