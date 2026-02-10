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
    int zigzag(TreeNode* root, int direction){
        if(root==NULL){
            return 0;
        }
        int l = zigzag(root->left,0);
        int r = zigzag(root->right,1);
        ans = max(ans,max(l,r));
        if(direction==0){
            return r+1;
        }
        return l+1;
    }
    int longestZigZag(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 0;
        int a = zigzag(root,0);
        return ans;
    }
};