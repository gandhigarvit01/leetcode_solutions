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
    int k = 0,v = 0;
    void findbottom(TreeNode* root,int vd){
        if(root==NULL){
            return ;
        }
        if(vd>v){
            k = root->val;
            v=vd;
        }
        findbottom(root->left,vd+1);
        findbottom(root->right,vd+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int vd = 0;
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        findbottom(root,vd);
        return k;
    }
};