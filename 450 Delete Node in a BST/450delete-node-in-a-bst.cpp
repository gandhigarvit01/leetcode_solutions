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
    TreeNode* deletenode(TreeNode* root, int key){
        if(root==NULL) return NULL;
        if(root->val > key){
            root->left = deletenode(root->left, key);
            return root;
        }
        else if(root->val < key){
            root->right = deletenode(root->right, key);
            return root;
        }
        else{
            if(!root->left && !root->right) return NULL;
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            TreeNode* temp = root->left;
            TreeNode* curr = root->right;
            while(curr->left!=NULL){
                curr = curr->left;
            }
            curr->left = temp;
            return root->right;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletenode(root,key);
    }
};