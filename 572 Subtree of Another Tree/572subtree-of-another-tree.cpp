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
    bool match(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL) return false;
        if(subRoot==NULL) return false;
        if(root->val != subRoot->val) return false;
        return match(root->left, subRoot->left) && match(root->right, subRoot->right);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(root==NULL) return false;
        bool is_root_match = match(root,subRoot);
        if(is_root_match) return true;
        bool l = dfs(root->left, subRoot);
        bool r = dfs(root->right, subRoot);
        return l || r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};