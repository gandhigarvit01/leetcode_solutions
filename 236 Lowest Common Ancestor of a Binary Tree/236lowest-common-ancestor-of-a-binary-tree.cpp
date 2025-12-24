/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* temp, TreeNode* p, TreeNode* q){
        if(temp==NULL){
            return NULL;
        }
        if(temp==p){
            return p;
        }
        if(temp==q){
            return q;
        }
        TreeNode* lefty = solve(temp->left,p,q);
        TreeNode* righty = solve(temp->right,p,q);
        if(lefty!=NULL){
            if(righty!=NULL){
                return temp;
            }
            else{
                return lefty;
            }
        }
        else{
            if(righty!=NULL){
                return righty;
            }
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        return solve(temp,p,q);
    }
};