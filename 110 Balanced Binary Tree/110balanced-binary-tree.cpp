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
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        auto lefty = solve(root->left);
        auto righty = solve(root->right);
        if(lefty.first==true && righty.first==true && (abs(lefty.second-righty.second)<=1)){
            return {true,max(lefty.second,righty.second)+1};
        }
        return {false,max(lefty.second,righty.second)+1};
    }
    bool isBalanced(TreeNode* root) {
        auto p = solve(root);
        if(p.first==true) return true;
        return false;
    }
};