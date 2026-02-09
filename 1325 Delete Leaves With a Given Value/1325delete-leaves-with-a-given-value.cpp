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
    void remove(TreeNode* root, int target){
        if(root==NULL) return;
        if(root->val==target){
            if(root->left==NULL && root->right==NULL){
                root->val = -1;
                return;
            }
        }
        remove(root->left,target);
        if(root->left!=NULL && root->left->val==-1) root->left = NULL;
        if(root->val==target){
            if(root->left==NULL && root->right==NULL){
                root->val = -1;
                return;
            }
        }
        remove(root->right,target);
        if(root->right!=NULL && root->right->val==-1) root->right = NULL;
        if(root->val==target){
            if(root->left==NULL && root->right==NULL){
                root->val = -1;
                return;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove(root,target);
        if(root->val==-1) return NULL;
        return root;
    }
};