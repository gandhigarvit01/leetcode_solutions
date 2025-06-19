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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto l = solve(root->left);
        auto r = solve(root->right);

        return {l.first+r.first+root->val-1,abs(l.first+r.first+root->val-1)+l.second+r.second};
        }
    int distributeCoins(TreeNode* root) {
        auto p = solve(root);
        return p.second;
    }
};