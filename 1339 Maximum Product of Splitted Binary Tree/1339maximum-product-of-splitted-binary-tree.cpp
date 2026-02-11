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
    int mod = 1e9+7;
    long long ans = INT_MIN;
    long long total = 0;
    void sum(TreeNode* root){
        if(root==NULL) return;
        total += root->val;
        sum(root->left);
        sum(root->right);
    }
    int breakpoint(TreeNode* root){
        if(root==NULL) return 0;
        int l = breakpoint(root->left);
        int r = breakpoint(root->right);
        long long currsum = l + r + root->val;
        ans = max(ans,currsum*(total-currsum));
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        sum(root);
        breakpoint(root);
        return (int)(ans % mod);
    }
};