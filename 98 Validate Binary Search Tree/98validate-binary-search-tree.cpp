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
    bool isvalid(TreeNode* root, long long l, long long r){
        if(root==NULL) return true;
        if(root->val<l || root->val>r) return false;
        bool lt = isvalid(root->left,l,(long long)root->val-1);
        bool rt = isvalid(root->right,(long long)root->val+1,r);
        return lt && rt;
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LLONG_MIN,LLONG_MAX);
    }
};