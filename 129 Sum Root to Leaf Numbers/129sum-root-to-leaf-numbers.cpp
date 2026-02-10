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
    int ans = 0;
    void sum(TreeNode* root, int curr){
        if(root==NULL) return;
        curr += root->val;
        if(!root->left && !root->right){
            ans += curr;
        }
        if(root->left) sum(root->left,curr*10);
        if(root->right) sum(root->right,curr*10);
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        return ans;
    }
};