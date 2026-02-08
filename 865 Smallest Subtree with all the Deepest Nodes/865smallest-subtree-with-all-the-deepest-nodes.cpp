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
    int maxdepth;
    void inorder(TreeNode* root, int depth){
        if(root==NULL) return;
        maxdepth = max(maxdepth,depth);
        inorder(root->left,depth+1);
        inorder(root->right,depth+1);
        return;
    }
    TreeNode* lca(TreeNode* root, int depth){
        if(root==NULL){
            return NULL;
        }
        if(depth==maxdepth){
            return root;
        }
        TreeNode* lefty = lca(root->left,depth+1);
        TreeNode* righty = lca(root->right,depth+1);
        if(lefty==NULL && righty==NULL) return NULL;
        if(lefty!=NULL && righty!=NULL) return root;
        if(lefty==NULL) return righty;
        return lefty;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        maxdepth = 0;
        inorder(root,0);
        return lca(root,0);
    }
};